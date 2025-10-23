#include "ram.cpp"
#include "cpu.cpp"
#include "rom.cpp"
#include <string>
#include <vector>

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
    void run() {
        while (true) {
            std::vector<char> instruction = rom.getInstruction(cpu.instructionPointer
                        , this->instructionSize);
            
            this->cpu.execute(instruction);
            cpu.instructionPointer += this->instructionSize;
        }
    }
private:
    Cpu cpu;
    Ram ram;
    Rom rom;

    const int instructionSize = 2;
};