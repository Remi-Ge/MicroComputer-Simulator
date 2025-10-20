#include <vector>
#include <iostream>

class Cpu {
public:
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
private:
    std::vector<char> registers;
};
