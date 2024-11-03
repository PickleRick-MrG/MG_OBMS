#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED
{
    public:
        LED();
        void LED_init(void);
        void LED_HeartBeat(void);
        void LED_Pulse(uint8_t freqHz);
    private:
        int _pin;
};

#endif