#pragma once

#include <stdint.h>
#include <string.h>
#include <elf.h>

class Utils
{
public:
    static void findelf(uint8_t* buffer, uint64_t* textstart, uint64_t* textend);
    static void getbinaryrepresentation(uint8_t* bytes, size_t numbytes, uint8_t* buf);
    static uint8_t tobit(uint8_t byte, uint8_t pos);
};
