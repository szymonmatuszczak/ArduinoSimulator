#include <stdint.h>
#include "ArduinoConstants.c"

void attachInterrupt(const uint8_t, const void(*)(), const uint8_t);
void pinMode(const uint8_t, const uint8_t);
void digitalWrite(const uint8_t, const uint8_t);
void delay(const unsigned long int);