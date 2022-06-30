#include <iostream>
#include <fstream>
#include <string>
#include "string.h"

#define NUL 0x0
#define ADD 0x1
#define NOT 0x2
#define XOR 0x3
#define AND 0x4
#define OR  0x5
#define GET 0x6
#define SET 0x7
#define JNZ 0x8

typedef uint16_t ram_addr;

using mp::string;

struct instruction {
    uint8_t op;
    ram_addr addr;
};


uint8_t acc=0;
uint16_t pl=0;

string lines[65536];

string fetch() {
    return lines[pl];
}

int str_to_hex(string hex) {
    std::string s = hex.c_str();
    unsigned int x = std::stoul(s, nullptr, 16);

    return x;
}

instruction decode(string str) {
    instruction inst={};
    string a=str.substr(0,3);
         if (a=="ADD") inst.op=ADD;
    else if (a=="NOT") inst.op=NOT;
    else if (a=="XOR") inst.op=XOR;
    else if (a=="AND") inst.op=AND;
    else if (a=="OR ") inst.op=OR ;
    else if (a=="GET") inst.op=GET;
    else if (a=="SET") inst.op=SET;
    else if (a=="JNZ") inst.op=JNZ;
    else               inst.op=NUL;

    printf("|%d|",a=="AND");

    string addr=str.substr(4,6);
    inst.addr=str_to_hex(addr);
}


int main() {
    // Load file
    std::ifstream file("program.txt");
    std::string line;
    int i=0;
    while (getline(file,line)) {
        lines[i]=string(line.c_str());
        i++;
    }

    printf(fetch());
    instruction inst=decode(fetch());
    printf(" -> ");
    printf("%d %d",inst.op,inst.addr);

    printf("\n");
    return 0;
}
