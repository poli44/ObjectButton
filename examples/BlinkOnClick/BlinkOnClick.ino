#include <ObjectButton.h>
#include <interfaces/IOnClickListener.h>

#define INPUT_PIN A1
#define LED_PIN LED_BUILTIN

class BlinkOnClick : private virtual IOnClickListener {
public:
    BlinkOnClick() = default;

    void init();
    void update();

private:
    void onClick(ObjectButton &button) override;

    ObjectButton button = ObjectButton(INPUT_PIN, /* activeLow */ true);
    int ledState = LOW;
};

void BlinkOnClick::onClick(ObjectButton &button) {
    if (button.getId() == INPUT_PIN) {
        Serial.println("Button clicked!");
      
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
}

void BlinkOnClick::init() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    button.setDebounceTicks(10);
    button.setOnClickListener(this);
}

void BlinkOnClick::update() {
    button.tick();
}

BlinkOnClick blinkOnClick = BlinkOnClick();

void setup() {
    blinkOnClick.init();
}

void loop() {
    blinkOnClick.update();
}
