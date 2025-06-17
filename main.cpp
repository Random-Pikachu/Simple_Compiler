#include "headers/lexer.h"
#include "headers/parser.h"
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string opCodeToString(OpCode op) {
    switch (op) {
        case OpCode::PUSH:  return "PUSH";
        case OpCode::POP:   return "POP";
        case OpCode::ADD:   return "ADD";
        case OpCode::SUB:   return "SUB";
        case OpCode::MUL:   return "MUL";
        case OpCode::DIV:   return "DIV";
        case OpCode::PRINT: return "PRINT";
        case OpCode::DUP:   return "DUP";
        case OpCode::SWAP:  return "SWAP";
        case OpCode::HALT:  return "HALT";
    }
    return "UNKNOWN";
}


int main(int argc, char const *argv[]){
    if (argc < 2){
        cerr << "Usage: " << argv[0] << " <file.asm>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << argv[1] << endl;
        return 1;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();
    
    Lexer lexer(source);
    vector<Token> tokens = lexer.tokenize();
    cout<<"======TOKENS======"<<endl;
    for (const auto& tok : tokens) {
        string typeStr;
        switch (tok.type) {
            case TokenType::INSTRUCTION: typeStr = "INSTRUCTION"; break;
            case TokenType::NUMBER:      typeStr = "NUMBER";      break;
            case TokenType::END:         typeStr = "EOF";         break;
        }
        cout << "[" << typeStr << " \"" << tok.value << "\" L" << tok.line << "]" << endl;
    }
    Parser parser(tokens);
    vector<Instruction> bytecode = parser.parse();
    cout<<"\n======BYTECODE======"<<endl;
    for (const auto& inst : bytecode) {
        cout << opCodeToString(inst.op) << " " << inst.operand << endl;
    }
    return 0;
}
