/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "modules/canbus_vehicle/ch/proto/ch.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class Turnsignalstatus513 : public ::apollo::drivers::canbus::ProtocolData<
                                ::apollo::canbus::Ch> {
 public:
  static const int32_t ID;
  Turnsignalstatus513();
  void Parse(const std::uint8_t* bytes, int32_t length,
             Ch* chassis) const override;

 private:
  // config detail: {'bit': 0, 'description': 'Lighting control(Status)',
  // 'enum': {0: 'TURN_SIGNAL_STS_NONE', 1: 'TURN_SIGNAL_STS_LEFT', 2:
  // 'TURN_SIGNAL_STS_RIGHT', 3: 'TURN_SIGNAL_STS_HAZARD_WARNING_LAMPSTS_ON'},
  // 'is_signed_var': False, 'len': 8, 'name': 'TURN_SIGNAL_STS', 'offset': 0.0,
  // 'order': 'intel', 'physical_range': '[0|2]', 'physical_unit': '',
  // 'precision': 1.0, 'type': 'enum'}
  Turnsignal_status__513::Turn_signal_stsType turn_signal_sts(
      const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'description': 'Lighting control(Status)',
  // 'enum': {0: 'LOW_BEAM_STS_ON', 1: 'LOW_BEAM_STS_OFF'}, 'is_signed_var':
  // False, 'len': 2, 'name': 'LOW_BEAM_STS', 'offset': 0.0, 'order': 'intel',
  // 'physical_range': '[0|2]', 'physical_unit': '', 'precision': 1.0, 'type':
  // 'enum'}
  Turnsignal_status__513::Low_beam_stsType low_beam_sts(
      const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
