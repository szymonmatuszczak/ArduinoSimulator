class Interrupt
{
    public:
        uint8_t pin;
        void(*ISR)();
        uint8_t mode;
        Interrupt(const uint8_t pinL, void(*ISRL)(), const uint8_t modeL)
        {
            pin = pinL;
            ISR = ISRL;
            mode = modeL;
        }
};

vector<Interrupt> SIM_INTERRUPTS;