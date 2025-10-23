#include "ram.cpp"
#include "cpu.cpp"
#include "rom.cpp"
#include <string>

class Machine {
public:
    Machine() {
        this->cpu = Cpu();
        this->ram = Ram();
        this->rom = Rom();
    }
    void loadProgram(std::string filePath) {
        rom.writeProgram(filePath);
    }
    void setRegister(int index, char value) {
        this->cpu.writeRegister(index, value);
    }
private:
    Cpu cpu;
    Ram ram;
    Rom rom;
};