#include <vector>
#include <iostream>

class Ram {
public:
    int size;
    Ram(int _size = 256) {
        this->size = _size;
        this->content = std::vector<char>(size, 0);
    }
    char read(int address) {
        if (address < 0 || address >= this->size) {
            std::cerr << "Warning: Invalid address, Returning 0x00" << std::endl;
            return 0;
        }
        return content[address];
    }
    void write(int address, char value) {
        if (address < 0 || address >= this->size) {
            std::cerr << "Warning: Invalid address, Writing Nothing" << std::endl;
            return;
        }
        this->content[address] = value;
    }
private:
    std::vector<char> content;
};