#include "include/disassemble.hpp"

int Disasm::disassemble(const uint8_t* buffer, uint32_t pos, uint32_t offset)
{
    Instruction* instr = new Instruction(&((uint8_t*)buffer)[pos + offset], offset, pos);
    printf("<0x%x:0x%x> - %s - %02x - %s - %d\n", instr->offset, instr->pos, instr->bits, instr->hex, instr->string.c_str(), instr->type);

    return sizeof(uint8_t) * 4;
}
