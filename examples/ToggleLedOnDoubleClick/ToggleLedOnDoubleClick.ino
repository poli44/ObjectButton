/**
 * @brief Single button, double click example.
 *
 * This sketch demonstrates using ObjectButton library with single button,
 * which will turn built-in LED on or off after being double-clicked.
 *
 * Copyright 2019 JSC electronics
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

#include <ObjectButton.h>
#include <interfaces/IOnDoubleClickListener.h>

constexpr static byte INPUT_PIN = A1;
constexpr static byte LED_PIN = LED_BUILTIN;

class ToggleLedOnDoubleClick : private virtual IOnDoubleClickListener {
public:
    ToggleLedOnDoubleClick() = default;

    void init();

    void update();

private:
    void onDoubleClick(ObjectButton &button) override;

    ObjectButton button = ObjectButton(INPUT_PIN);
    byte ledState = LOW;
};

void ToggleLedOnDoubleClick::onDoubleClick(ObjectButton &button) {
    if (button.getId() == INPUT_PIN) {
        Serial.println("Button double-clicked!");

        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
}

void ToggleLedOnDoubleClick::init() {
    // Setup the Serial port. See http://arduino.cc/en/Serial/IfSerial
    Serial.begin(9600);
    while (!Serial) { ; // wait for serial port to connect. Needed for Leonardo only
    }
    pinMode(LED_PIN, OUTPUT);
    button.setDebounceTicks(10);
    button.setOnDoubleClickListener(this);
}

void ToggleLedOnDoubleClick::update() {
    button.tick();
}

ToggleLedOnDoubleClick toggleLedOnDoubleClick = ToggleLedOnDoubleClick();

void setup() {
    toggleLedOnDoubleClick.init();
}

void loop() {
    toggleLedOnDoubleClick.update();
}
