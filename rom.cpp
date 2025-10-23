#include <vector>
#include <iostream>
#include <fstream>

class Rom {
public:
    int size;
    int instructionPointer = 0;
    Rom(int _size = 1024) {
        this->size = _size;
        this->content = std::vector<char>(this->size, 0);
    }
    char read(int address) {
        if (address < 0 || address >= this->size) {
            std::cerr << "Warning: Invalid address, Returning 0x00" << std::endl;
            return 0;
        }
        return content[address];
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
    std::vector<char> content;
};