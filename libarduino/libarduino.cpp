#define exported extern "C"
#include "ArduinoConstants.c"
#include "SupportedSubsystems/DigitalIO.cpp"
#include "SupportedSubsystems/Interrupts.cpp"
#include "OnUpdate.cpp"
exported void pinMode(const uint8_t pin, const uint8_t mode)
{
    if(pin < SIM_DEVICE.size())
    {
        SIM_DEVICE[pin].mode = mode;
        onUpdate();
    }
}

exported void digitalWrite(const uint8_t pin, const uint8_t value)
{
    if(pin < SIM_DEVICE.size() && (value == LOW || value == HIGH))
    {
        SIM_DEVICE[pin].value = value;
        onUpdate();
    }
}

exported void delay(const unsigned long int delay)
{
    this_thread::sleep_for(chrono::milliseconds(delay));
}
exported void attachInterrupt(const uint8_t pin, void(*ISR)(), const uint8_t mode)
{
    if(pin < SIM_DEVICE.size() && (mode == RISING || mode == FALLING))
        SIM_INTERRUPTS.push_back(Interrupt(pin, ISR, mode));
}

#include "SupportedTargets/ATTiny2313.cpp"
