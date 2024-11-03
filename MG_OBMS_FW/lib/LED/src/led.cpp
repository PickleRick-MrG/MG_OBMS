#include "led.h"


LED::LED() { }

void LED::LED_init(void) {
    pinMode(LED_BUILTIN, OUTPUT);
}

void LED::LED_HeartBeat(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}

void LED::LED_Pulse(uint8_t freqHz) {
    uint8_t u8_period = (uint8_t)(floor((1/freqHz)*1000));
    uint8_t u8_halfT = (uint8_t)(floor(u8_period/2));
    digitalWrite(LED_BUILTIN, HIGH);
    delay(u8_halfT);
    digitalWrite(LED_BUILTIN, LOW);
    delay(u8_halfT);
}