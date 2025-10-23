import sys
import struct

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <program> <output>")
    exit(1)

def parseRegister(register):
    if not register or register[0] != "R":
        print("ERROR: Wrong Register Name")
        exit(1)
    return int(register[1:])

def parseNumber(number):
    result = int(number)
    if result < 0 or result >= 256:
        print("ERROR: value has to be between 0 and 255")
        exit(1)
    return result

source_path = sys.argv[1]
output_path = sys.argv[2]

source_file = open(source_path, "r")
output_file = open(output_path, "wb")
    
lines = source_file.read().split("\n")
for i in range(len(lines)):
    elements = lines[i].split(" ")
    if not elements[0]:
        continue
    binary = 0
    match elements[0]:
        case "NONE": # 0x0
            pass
        case "LOAD": # 0x1
            binary += (1 << 12) + (parseRegister(elements[1]) << 8) + parseNumber(elements[2])
            print(binary)
        case "STORE": # 0x2
            binary += (2 << 12) + (parseRegister(elements[1]) << 8) + parseNumber(elements[2])
        case "HALT": # 0xf
            binary += 15 << 12
        case _:
            print(f"ERROR: Unknown Operand \"{elements[0]}\"")
            exit(1)
    output_file.write(struct.pack('>H', binary))
    print(struct.pack('>H', binary))

source_file.close()
output_file.close()