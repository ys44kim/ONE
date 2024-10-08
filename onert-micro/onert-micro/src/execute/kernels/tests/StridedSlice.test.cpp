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

#include "execute/OMTestUtils.h"
#include "test_models/strided_slice/FloatStridedSliceKernel.h"
#include "test_models/strided_slice/IntStridedSliceKernel.h"
#include "test_models/strided_slice/S8StridedSliceKernel.h"
#include "test_models/strided_slice/NegStridedSliceKernel.h"

namespace onert_micro
{
namespace execute
{
namespace testing
{

using namespace testing;

class StridedSliceTest : public ::testing::Test
{
  // Do nothing
};

TEST_F(StridedSliceTest, Float_P)
{
  onert_micro::test_model::TestDataFloatStridedSlice test_data_kernel;
  std::vector<float> output_data_vector =
    onert_micro::execute::testing::checkKernel<float>(1, &test_data_kernel);
  EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
}

TEST_F(StridedSliceTest, INT32_P)
{
  onert_micro::test_model::TestDataIntStridedSlice test_data_kernel;
  std::vector<int32_t> output_data_vector =
    onert_micro::execute::testing::checkKernel<int32_t>(1, &test_data_kernel);
  EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
}

TEST_F(StridedSliceTest, S8_P)
{
  onert_micro::test_model::TestDataS8StridedSlice test_data_kernel;
  std::vector<int8_t> output_data_vector =
    onert_micro::execute::testing::checkKernel<int8_t>(1, &test_data_kernel);
  EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
}

TEST_F(StridedSliceTest, Input_output_type_mismatch_NEG)
{
  onert_micro::test_model::NegTestDataInputOutputTypeMismatchStridedSliceKernel test_data_kernel;

  EXPECT_DEATH(checkNEGSISOKernel(&test_data_kernel), "");
}

TEST_F(StridedSliceTest, Incorrect_type_param_begin_NEG)
{
  onert_micro::test_model::NegTestDataIncorrectTypeParamBeginStridedSliceKernel test_data_kernel;

  EXPECT_DEATH(checkNEGSISOKernel(&test_data_kernel), "");
}

TEST_F(StridedSliceTest, Incorrect_type_param_strides_NEG)
{
  onert_micro::test_model::NegTestDataIncorrectTypeParamStridesStridedSliceKernel test_data_kernel;

  EXPECT_DEATH(checkNEGSISOKernel(&test_data_kernel), "");
}

} // namespace testing
} // namespace execute
} // namespace onert_micro
