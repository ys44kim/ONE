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

#ifndef ONERT_MICRO_TEST_MODELS_S8_SPACE_TO_DEPTH_KERNEL_H
#define ONERT_MICRO_TEST_MODELS_S8_SPACE_TO_DEPTH_KERNEL_H

#include "TestDataSpaceToDepthBase.h"

namespace onert_micro
{
namespace test_model
{
namespace space_to_depth_s8
{
/*
 * SpaceToDepth Kernel:
 *
 *      Input(1, 4, 4, 3)
 *            |
 *       SpaceToDepth
 *            |
 *      Output(1, 2, 2, 12)
 */
const unsigned char test_kernel_model_circle[] = {
  0x18, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0xc4, 0x01, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff,
  0xfc, 0xff, 0xff, 0xff, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00,
  0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x64, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0e, 0x00, 0x16, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00,
  0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x92, 0xff, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x44, 0x00, 0x00, 0x00, 0x84, 0xff, 0xff, 0xff, 0x2c, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x43, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x13, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
  0x54, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x14, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x7f, 0x43, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x1a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d,
  0x74, 0x66, 0x6c, 0x69, 0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};
const std::vector<int8_t> input_data = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
  24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
const std::vector<int8_t> reference_output_data = {
  0,  1,  2,  3,  4,  5,  12, 13, 14, 15, 16, 17, 6,  7,  8,  9,  10, 11, 18, 19, 20, 21, 22, 23,
  24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 30, 31, 32, 33, 34, 35, 42, 43, 44, 45, 46, 47};
} // namespace space_to_depth_s8

class TestDataS8SpaceToDepth : public TestDataSpaceToDepthBase<int8_t>
{
public:
  TestDataS8SpaceToDepth()
  {
    _input_data = space_to_depth_s8::input_data;
    _reference_output_data = space_to_depth_s8::reference_output_data;
    _test_kernel_model_circle = space_to_depth_s8::test_kernel_model_circle;
  }

  ~TestDataS8SpaceToDepth() override = default;
};

} // namespace test_model
} // namespace onert_micro

#endif // ONERT_MICRO_TEST_MODELS_S8_SPACE_TO_DEPTH_KERNEL_H
