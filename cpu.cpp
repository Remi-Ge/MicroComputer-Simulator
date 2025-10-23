#include <vector>
#include <iostream>
#include <bitset>

class Cpu {
public:
    int instructionPointer = 0;
    int registerCount;
    Cpu(int _registerCount = 8) {
        this->registerCount = _registerCount;
        this->registers = std::vector<char>(this->registerCount, 0);
    }
    char readRegister(int index) {
        if (index < 0 || index >= this->registerCount) {
            std::cerr << "Warning: Invalid Register Index, Returning 0x00" << std::endl;
            return 0;
        }
        return registers[index];
    }
    void writeRegister(int index, char value) {
        if (index < 0 || index >= this->registerCount) {
            std::cerr << "Warning: Invalid Register Index, Writing Nothing" << std::endl;
            return;
        }
        this->registers[index] = value;
    }
    void execute(std::vector<char> instruction) {
        unsigned char firstByte = instruction[0];
        unsigned char secondByte = instruction[1];
        unsigned char operand = (firstByte & 0xF0) >> 4;
        switch (operand) {
            case 0x0: // NONE
                break;
            case 0xf: // HALT
                exit(0);
            default: // Unknown Instruction
                std::cout << "Warning: Unknown Instruction" << std::endl;
        }
    }
private:
    std::vector<char> registers;
};
