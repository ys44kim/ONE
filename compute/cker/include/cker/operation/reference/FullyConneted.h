/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
 * Copyright 2024 The TensorFlow Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __NNFW_CKER_REFERENCE_FULLY_CONNECTED_H__
#define __NNFW_CKER_REFERENCE_FULLY_CONNECTED_H__

#include "cker/Types.h"
#include "cker/Shape.h"

#include <iostream>

namespace nnfw
{
namespace cker
{
namespace reference
{

inline void FullyConnected(const FullyConnectedParams &params, const Shape &input_shape,
                           const float *input_data, const Shape &weights_shape,
                           const float *weights_data, const Shape &, const float *bias_data,
                           const Shape &, float *output_data)
{
  UNUSED_RELEASE(params);
  UNUSED_RELEASE(input_shape);
  UNUSED_RELEASE(input_data);
  UNUSED_RELEASE(weights_shape);
  UNUSED_RELEASE(weights_data);
  UNUSED_RELEASE(bias_data);
  UNUSED_RELEASE(output_data);

  std::cout << "GGML FullyConneted" << std::endl;
}

} // namespace reference
} // namespace cker
} // namespace nnfw

#endif // __NNFW_CKER_REFERENCE_FULLY_CONNECTED_H__
