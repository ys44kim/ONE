/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __ONERT_IR_TRAIN_TRAINABLE_OPERATION_H__
#define __ONERT_IR_TRAIN_TRAINABLE_OPERATION_H__

#include "ITrainableOperation.h"

namespace onert::ir::train
{

class TrainableOperation : public ITrainableOperation
{
public:
  virtual ~TrainableOperation() = default;

public:
  void disableWeightsUpdate() final { _trainable = false; }

  void enableWeightsUpdate() final { _trainable = true; }

  virtual bool isWeightsUpdateEnabled() const final { return _trainable; }

  void enableBackward() final { _required_for_backward = true; }
  void disableBackward() final { _required_for_backward = false; }
  virtual bool isRequiredForBackward() const final { return _required_for_backward; }

private:
  bool _trainable = false;
  bool _required_for_backward = false;
};

} // namespace onert::ir::train

#endif // __ONERT_IR_TRAIN_TRAINABLE_OPERATION_H__
