#include <Arduino.h>

int i = 0;

void setup() {
    ledcSetup(0, 5000, 13);
    ledcAttachPin(LED_BUILTIN, 0);
}

void loop() {
    ledcWrite(0, i);
    delay(20);
    i = (i <= 8191) ? i+100 : 0;
}
