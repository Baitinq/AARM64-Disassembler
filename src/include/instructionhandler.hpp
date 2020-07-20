#pragma once

#include <tuple>
#include "instructions.hpp"

class InstructionHanlder
{
public:
    static InstructionType getInstruction(Instruction* instr);
    static std::string getInstructionString(Instruction* instr);
private:
    static std::tuple<std::string, std::string, InstructionType> getTpl(Instruction* instr);
    static std::tuple<std::string, std::string, InstructionType> array[6];
};
