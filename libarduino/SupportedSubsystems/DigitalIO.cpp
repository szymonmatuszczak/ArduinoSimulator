class Pin
{
    public:
        uint8_t port;
        uint8_t portPin;
        uint8_t mode;
        uint8_t value;
        Pin(const uint8_t portL, const uint8_t portPinL, const uint8_t modeL=INPUT, const uint8_t valueL=LOW)
        {
            mode = modeL;
            port = portL;
            portPin = portPinL;
            value = valueL;
        }
        char getPortName()
        {
            if(port == SIM_PORTA) return 'A';
            if(port == SIM_PORTB) return 'B';
            if(port == SIM_PORTC) return 'C';
            if(port == SIM_PORTD) return 'D';
        }
        string getMode()
        {
            if(mode == INPUT) return "INPUT";
            if(mode == INPUT_PULLUP) return "INPUT_PULLUP";
            if(mode == OUTPUT) return "OUTPUT";
        }
        string getValue()
        {
            if(value == LOW) return "LOW";
            if(value == HIGH) return "HIGH";
        }
};

vector<Pin> SIM_DEVICE_ATTINY2313 =
{
    Pin(SIM_PORTD, 0),
    Pin(SIM_PORTD, 1),
    Pin(SIM_PORTA, 1),
    Pin(SIM_PORTA, 0),
    Pin(SIM_PORTD, 2), //INT0
    Pin(SIM_PORTD, 3), //INT1
    Pin(SIM_PORTD, 4),
    Pin(SIM_PORTD, 5),
    Pin(SIM_PORTD, 6),
    Pin(SIM_PORTB, 0),
    Pin(SIM_PORTB, 1),
    Pin(SIM_PORTB, 2),
    Pin(SIM_PORTB, 3),
    Pin(SIM_PORTB, 4),
    Pin(SIM_PORTB, 5),
    Pin(SIM_PORTB, 6),
    Pin(SIM_PORTB, 7),
    Pin(SIM_PORTA, 2)
};

vector<Pin>& SIM_DEVICE = SIM_DEVICE_ATTINY2313;