#include "ram.cpp"
#include "cpu.cpp"

class Machine {
public:
    Machine() {
        this->cpu = Cpu();
        this->ram = Ram();
    }
    void setRegister(int index, char value) {
        this->cpu.writeRegister(index, value);
    }
private:
    Cpu cpu;
    Ram ram;
};