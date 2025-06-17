#include "../headers/parser.h"
#include <bits/stdc++.h>
using namespace std;

Parser::Parser(const vector<Token>& tokens): tokens_(tokens), pos_(0) {}

vector<Instruction> Parser::parse() {
    vector<Instruction> bytecode;

    while (current().type != TokenType::END) {

        if (current().type != TokenType::INSTRUCTION) {
            throw runtime_error(
                "Line " + to_string(current().line) +
                ": expected instruction, got '" + current().value + "'"
            );
        }

        OpCode op = stringToOpCode(current().value);
        advance();
        if (needsOperand(op)) {
            if (current().type != TokenType::NUMBER) {
                throw runtime_error(
                    "Line " + to_string(current().line) +
                    ": expected number after 'push'"
                );
            }
            int value = stoi(current().value);
            bytecode.push_back({op, value});
            advance();
        }
        else {
            bytecode.push_back({op, 0});
        }
    }

    return bytecode;
}

OpCode Parser::stringToOpCode(const string& word) {
    static const unordered_map<string, OpCode> map = {
        {"push",  OpCode::PUSH},
        {"pop",   OpCode::POP},
        {"add",   OpCode::ADD},
        {"sub",   OpCode::SUB},
        {"mul",   OpCode::MUL},
        {"div",   OpCode::DIV},
        {"print", OpCode::PRINT},
        {"dup",   OpCode::DUP},
        {"swap",  OpCode::SWAP},
        {"halt",  OpCode::HALT}
    };

    auto it = map.find(word);
    if (it == map.end()) {
        throw runtime_error("Unknown instruction: '" + word + "'");
    }
    return it->second;
}

bool Parser::needsOperand(OpCode op) {
    return op == OpCode::PUSH;
}

const Token& Parser::current() {
    return tokens_[pos_];
}

Token Parser::advance() {
    Token tok = tokens_[pos_];
    pos_++;
    return tok;
}