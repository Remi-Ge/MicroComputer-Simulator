#include <vector>
#include <iostream>
#include <fstream>

class Rom {
public:
    int size;
    Rom(int _size = 1024) {
        this->size = _size;
        this->content = std::vector<unsigned char>(this->size, 0);
    }
    unsigned char read(int address) {
        if (address < 0 || address >= this->size) {
            std::cerr << "Warning: Invalid address, Returning 0x00" << std::endl;
            return 0;
        }
        return content[address];
    }
    std::vector<unsigned char> getInstruction(int address, int instructionSize) {
        std::vector<unsigned char> instruction;
        for (int i = 0; i < instructionSize; i++) {
            int addr = address + i;
            if (addr < this->size) {
                instruction.push_back(this->read(addr));
            } else {
                std::cerr << "ERROR: Invalid ROM Address, Exiting" << std::endl;
                exit(1);
            }
        }
        return instruction;
    }
    void writeProgram(std::string filePath) {
        std::ifstream file(filePath, std::ios::binary);
        if (!file) {
            std::cerr << "Warning: Can't open " << filePath << ", writing nothing" << std::endl;
            return;
        }
        int index = 0;
        char byte;
        while (file.get(byte)) {
            if (index > this->size) {
                std::cerr << "Warning: Exceeded ROM Size, writing stopped" << std::endl;
                break;
            }
            this->content[index] = byte;
            index++;
        }
        file.close();
    }
private:
    std::vector<unsigned char> content;
};