#include "machine.cpp"
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <program>" << std::endl;
        return 1;
    }
    std::string programPath = argv[1];
    Machine machine = Machine();
    machine.loadProgram(programPath);
    machine.run();
}
