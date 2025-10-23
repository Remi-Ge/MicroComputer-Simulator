import sys
import struct

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <program> <output>")
    exit(1)

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
        case "NONE":
            pass
        case "HALT":
            binary += 15 << 12
        case _:
            print(f"ERROR: Unknown Operand \"{elements[0]}\"")
            exit(1)
    output_file.write(struct.pack('>H', binary))
    print(struct.pack('>H', binary))

source_file.close()
output_file.close()