/**
 *  @file       AnalogSensor.cpp
 *  Project     ObjectButton
 *  @brief      An Arduino library for detecting button actions.
 *  @author     Vladimír Záhradník
 *  License     Apache-2.0 - Copyright (c) 2019-2020 JSC electronics
 *
 *  Copyright (c) 2019-2020 JSC electronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "AnalogSensor.h"
using namespace jsc;

/**
 * @brief Constructor for the class.
 * @param sensorId a unique button ID. Accepted values: 0 - 255.
 * @param pin an input pin to use for the button.
 * @param voltage a voltage returned by the analogRead() function.
 * @param inputPullUp determines pin state after button press. Set to <code>true</code> if voltage level
 * on input pin is <code>LOW</code> after button is pressed. Otherwise set to <code>false</code>.
 * This parameter is optional and defaults to <code>true</code>.
 */
AnalogSensor::AnalogSensor(uint8_t sensorId,
                           uint8_t pin,
                           uint16_t voltage,
                           bool inputPullUp) : AnalogButton(sensorId, pin, voltage, inputPullUp) {}
