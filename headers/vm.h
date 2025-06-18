#pragma once
#include "opcodes.h"
#include "parser.h"

class VM {
    public:
        VM(const vector<Instruction>& instructions);
        void run();
    private:
        const vector<Instruction>& instructions;
        vector<int> stack;
        size_t pc;

        void execute(const Instruction& instruction);
        void push(int value);
        int pop();
        int peek();
};