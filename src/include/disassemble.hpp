#pragma once

#include <stdint.h>
#include <stdio.h>

#include "utils.hpp"
#include "instructions.hpp"

class Disasm
{
public:
    static int disassemble(const uint8_t* buffer, uint32_t pos, uint32_t offset);
};
