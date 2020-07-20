#pragma once

#include <stdint.h>
#include <string>

#include "utils.hpp"
#include "disassemble.hpp"

enum class InstructionType
{
    NUL,
    ADD,
    ADD_SHIFTED_REG,
    SUB,
    MOV,
    MOVZ,
    RET,
    NOP
};

class Instruction
{
public:
    Instruction(uint8_t* hex, uint32_t offset, uint32_t pos);
    uint8_t bits[33];
    uint32_t offset;
    uint32_t pos;
    uint32_t addr;
    InstructionType type;
    std::string string;
    uint32_t hex;
};

#include "instructionhandler.hpp"

