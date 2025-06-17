#pragma once
#include "opcodes.h"
#include "lexer.h"
#include <bits/stdc++.h>
using namespace std;

struct Instruction {
    OpCode op;
    int operand;   
};

class Parser {
public:
    explicit Parser(const vector<Token>& tokens);
    vector<Instruction> parse();

private:
    vector<Token> tokens_;
    size_t pos_;

    OpCode stringToOpCode(const string& word);
    bool needsOperand(OpCode op);

    const Token& current();
    Token advance();
};