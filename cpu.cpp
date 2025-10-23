#include <vector>
#include <iostream>
#include <bitset>
#include "ram.cpp"

class Cpu {
public:
    int instructionPointer = 0;
    int registerCount;
    Cpu(int _registerCount = 8) {
        this->registerCount = _registerCount;
        this->registers = std::vector<unsigned char>(this->registerCount, 0);
        this->ram = Ram();
    }
    unsigned char readRegister(int index) {
        if (index < 0 || index >= this->registerCount) {
            std::cerr << "Warning: Invalid Register Index, Returning 0x00" << std::endl;
            return 0;
        }
        return registers[index];
    }
    void writeRegister(int index, unsigned char value) {
        if (index < 0 || index >= this->registerCount) {
            std::cerr << "Warning: Invalid Register Index, Writing Nothing" << std::endl;
            return;
        }
        this->registers[index] = value;
    }
    void execute(std::vector<unsigned char> instruction) {
        unsigned char firstByte = instruction[0];
        unsigned char secondByte = instruction[1];
        unsigned char operand = (firstByte & 0xF0) >> 4;
        switch (operand) {
            case 0x0: // NONE
                break;
            case 0x1: // LOAD
                this->writeRegister(firstByte & 0x0F, secondByte);
                break;
            case 0x2: // STORE
                this->ram.write(secondByte, this->readRegister(firstByte & 0x0F));
                break;
            case 0xf: // HALT
                exit(0);
            default: // Unknown Instruction
                std::cout << "Warning: Unknown Instruction" << std::endl;
        }
    }
private:
    std::vector<unsigned char> registers;
    Ram ram;
};
