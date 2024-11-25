/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __GGML_LOG_H__
#define __GGML_LOG_H__

#include <stdint.h>

void ggml_log_init(void);
void ggml_log_write(int32_t line, int64_t arg0, int64_t arg1, int64_t arg2, int64_t arg3);
void ggml_log_update_tid(void);
void ggml_log_update_cpuId(void);

#if 1 //DEBUG
#define GGML_LOG(arg0, arg1, arg2, arg3) \
do {\
  ggml_log_write(__LINE__, (int64_t)(arg0), (int64_t)(arg1), (int64_t)(arg2), (int64_t)(arg3)); \
}while(0);
#else
#define GGML_LOG(arg0, arg1, arg2, arg3)
#endif


#endif // __GGML_LOG_H__
