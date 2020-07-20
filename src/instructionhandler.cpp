#include "include/instructionhandler.hpp"

static bool cmpInstruction(uint8_t* bits, std::string mask)
{
    for(int i = 0; i < 32; i++)
    {
        if(bits[i] != mask.at(i) && mask.at(i) != 'x')
            return false;
    }
    return true;
}

std::tuple<std::string, std::string, InstructionType> InstructionHanlder::getTpl(Instruction* instr)
{
    for(std::tuple<std::string, std::string, InstructionType>  tpl : array)
    {
        if(cmpInstruction(instr->bits, std::get<0>(tpl)))
            return tpl;
    }
    return {"", "NULL", InstructionType::NUL};
}

InstructionType InstructionHanlder::getInstruction(Instruction *instr)
{
    return std::get<2>(getTpl(instr));
}

std::string InstructionHanlder::getInstructionString(Instruction *instr)
{
    std::string res;
    res.append(std::get<1>(getTpl(instr)));

    return res;
}

std::tuple<std::string, std::string, InstructionType> InstructionHanlder::array[6] =
{
  { "10010001xxxxxxxxxxxxxxxxxxxxxxxx", "ADD", InstructionType::ADD },
  { "10001011xx0xxxxxxxxxxxxxxxxxxxxx", "ADD", InstructionType::ADD_SHIFTED_REG },
  { "10101010000xxxxx00000011111xxxxx", "MOV", InstructionType::MOV},
  { "110100101xxxxxxxxxxxxxxxxxxxxxxx", "MOV", InstructionType::MOVZ},
  { "1101011001011111000000xxxxx00000", "RET", InstructionType::RET},
  { "11010101000000110010000000011111", "NOP", InstructionType::NOP}
};

/* MAYBE MAKE SUBCLASSES oF INSTR TYPES, I THINK THERE ARE 4
 *
 *
 * THAT WAY WE HAVE ACCESS TO REGS AND SHIT*/
