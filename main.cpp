#include <iostream>
#include <string>
#include "string.hpp"

#define NUL 0x00
#define ADD 0x01
#define NOT 0x02
#define XOR 0x03
#define AND 0x04
#define OR  0x05
#define GET 0x06
#define SET 0x07
#define JNZ 0x08

using mp::string;

uint8_t acc=0;
uint16_t pl=0;

int main() {
    std::cout << str1+str2.substr(1,2) << std::endl;
    return 0;
}
