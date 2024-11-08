/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
 #include <sched.h>

#include "ggml-log.h"

static inline struct timespec ggml_gettime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts;
}

typedef struct  {
  struct timespec ts;
  int32_t tid;
  int32_t core_id;
  int32_t line;
  int64_t args[4];
} ggml_log_type;

#define MAX_CORE_N      64
#define LOG_MAX_SIZE    1024

static ggml_log_type log_buffer[MAX_CORE_N][LOG_MAX_SIZE];
static int32_t log_head[MAX_CORE_N];
static int32_t log_tail[MAX_CORE_N];

static __thread int32_t log_tid = 0;
static __thread int32_t log_core_id = 0;

static inline void convert_local_time(struct timespec ts, char *buffer, unsigned int buf_size)
{
  time_t seconds = ts.tv_sec;
  long nanoseconds = ts.tv_nsec;

  struct tm *local_time = localtime(&seconds);

  strftime(buffer, buf_size, "%Y-%m-%d %H:%M:%S", local_time);
  snprintf(&buffer[strlen(buffer)], buf_size - strlen(buffer), ".%09ld", nanoseconds);
}

void ggml_log_write(int32_t line, int64_t arg0, int64_t arg1, int64_t arg2, int64_t arg3)
{
  if ((log_head[log_core_id] + 1) % LOG_MAX_SIZE == log_tail[log_core_id])
  {
    printf("log buffer overflow\n");
    return; // overflow case, do nothing.
  }

  log_buffer[log_core_id][log_head[log_core_id]].ts = ggml_gettime();
  log_buffer[log_core_id][log_head[log_core_id]].tid = log_tid;
  log_buffer[log_core_id][log_head[log_core_id]].core_id = log_core_id;
  log_buffer[log_core_id][log_head[log_core_id]].line = line;
  log_buffer[log_core_id][log_head[log_core_id]].args[0] = arg0;
  log_buffer[log_core_id][log_head[log_core_id]].args[1] = arg1;
  log_buffer[log_core_id][log_head[log_core_id]].args[2] = arg2;
  log_buffer[log_core_id][log_head[log_core_id]].args[3] = arg3;

  // printf("gettime : %d, %ld, %ld\n", log_buffer[log_head].tid, \
  //   log_buffer[log_head].ts.tv_sec, log_buffer[log_head].ts.tv_nsec);

  log_head[log_core_id] = (log_head[log_core_id] + 1) % LOG_MAX_SIZE;  
}

static void ggml_log_print(void)
{
  for(int core_id = 0; core_id < MAX_CORE_N; core_id++)
  {
    if(log_head[core_id] == log_tail[core_id])
    {
      continue;
    }

    while(log_head[core_id] != log_tail[core_id])
    {
      char local_time[80];
      memset(local_time, 0x0, sizeof(local_time));

      convert_local_time(log_buffer[core_id][log_tail[core_id]].ts, local_time, 80);

      printf("[%s][core:%2d][tid:%6d][line:%5d] : %10ld, %10ld, %10ld %10ld \n", \
              local_time, log_buffer[core_id][log_tail[core_id]].core_id, \
              log_buffer[core_id][log_tail[core_id]].tid, \
              log_buffer[core_id][log_tail[core_id]].line, \
              log_buffer[core_id][log_tail[core_id]].args[0], \
              log_buffer[core_id][log_tail[core_id]].args[1], \
              log_buffer[core_id][log_tail[core_id]].args[2], \
              log_buffer[core_id][log_tail[core_id]].args[3]);

      log_tail[core_id] = (log_tail[core_id] + 1) % LOG_MAX_SIZE;
    }
  }
}

static void ggml_log_print_thread(void *arg)
{
  while(1)
  {    
    ggml_log_print(); // print log every 100ms
    usleep(10000); // 10ms sleep
  }
}

void ggml_log_update_tid(void)
{
  log_tid = gettid();
}

void ggml_log_update_cpuId(void)
{
  log_core_id = sched_getcpu(); // get current cpu id
}

void ggml_log_init(void)
{
  pthread_t log_print_thread;

  if(pthread_create(&log_print_thread, NULL, ggml_log_print_thread, NULL)!= 0)
  {
    perror("pthread_create error\n");
    return;
  }

  for(int core_id = 0; core_id < MAX_CORE_N; core_id++)
  {
    log_head[core_id] = 0;
    log_tail[core_id] = 0;

    for(int i = 0; i < LOG_MAX_SIZE; i++) 
    {
      log_buffer[core_id][i].ts.tv_sec = 0;
      log_buffer[core_id][i].ts.tv_nsec = 0;
      log_buffer[core_id][i].tid = 0;
      log_buffer[core_id][i].core_id = 0;
      log_buffer[core_id][i].line = 0;
      log_buffer[core_id][i].args[0] = 0;
      log_buffer[core_id][i].args[1] = 0;
      log_buffer[core_id][i].args[2] = 0;
      log_buffer[core_id][i].args[3] = 0;    
    }
  }

  ggml_log_update_tid();
  ggml_log_update_cpuId();
}
