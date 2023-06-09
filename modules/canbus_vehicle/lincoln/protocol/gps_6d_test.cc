/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/canbus_vehicle/lincoln/protocol/gps_6d.h"

#include "gtest/gtest.h"

namespace apollo {
namespace canbus {
namespace lincoln {

TEST(Gps6dTest, General) {
  uint8_t data[8] = {0x56, 0x52, 0x53, 0x54, 0xF1, 0xF2, 0xF3, 0xF4};
  int32_t length = 8;
  Lincoln cd;
  Gps6d gps;
  gps.Parse(data, length, &cd);

  EXPECT_TRUE(cd.basic().gps_valid());
  EXPECT_DOUBLE_EQ(cd.basic().latitude(), -244.245646);
  EXPECT_DOUBLE_EQ(cd.basic().longitude(), -61.779717);

  EXPECT_EQ(data[0], 0b01010110);
  EXPECT_EQ(data[1], 0b01010010);
  EXPECT_EQ(data[2], 0b01010011);
  EXPECT_EQ(data[3], 0b01010100);
  EXPECT_EQ(data[4], 0b11110001);
  EXPECT_EQ(data[5], 0b11110010);
  EXPECT_EQ(data[6], 0b11110011);
  EXPECT_EQ(data[7], 0b11110100);
}

}  // namespace lincoln
}  // namespace canbus
}  // namespace apollo
