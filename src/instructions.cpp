#include "include/instructions.hpp"

Instruction::Instruction(uint8_t* hex, uint32_t offset, uint32_t pos)
{
    this->hex = (hex[3] << 24) | (hex[2] << 16)| (hex[1] << 8) | hex[0];
    Utils::getbinaryrepresentation(hex, 4, this->bits);
    this->bits[32] = '\0';
    this->offset = offset;
    this->pos = pos;
    this->addr = this->offset + this->pos;
    this->string = InstructionHanlder::getInstructionString(this);
    this->type = InstructionHanlder::getInstruction(this);
}
