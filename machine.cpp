#include "cpu.cpp"
#include "rom.cpp"
#include <string>
#include <vector>

class Machine {
public:
    Machine() {
        this->cpu = Cpu();
        this->rom = Rom();
    }
    void loadProgram(std::string filePath) {
        rom.writeProgram(filePath);
    }
    void setRegister(int index, unsigned char value) {
        this->cpu.writeRegister(index, value);
    }
    void run() {
        while (true) {
            std::vector<unsigned char> instruction = rom.getInstruction(cpu.instructionPointer
                        , this->instructionSize);
            this->cpu.execute(instruction);
            cpu.instructionPointer += this->instructionSize;
        }
    }
private:
    Cpu cpu;
    Rom rom;

    const int instructionSize = 2;
};