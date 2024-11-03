#include <Arduino.h>
#include "led.h"

LED *obj_LED;

void setup() {

  obj_LED = new LED();
  obj_LED->LED_init(); 
}

void loop() {

  obj_LED->LED_HeartBeat();
}