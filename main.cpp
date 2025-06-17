#include "headers/lexer.h"
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

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
    
    for (const auto& tok : tokens) {
        string typeStr;
        switch (tok.type) {
            case TokenType::INSTRUCTION: typeStr = "INSTRUCTION"; break;
            case TokenType::NUMBER:      typeStr = "NUMBER";      break;
            case TokenType::LABEL:       typeStr = "LABEL";       break;
            case TokenType::LABEL_REF:   typeStr = "LABEL_REF";   break;
            case TokenType::END:         typeStr = "EOF";         break;
        }
        cout << "[" << typeStr << " \"" << tok.value << "\" L" << tok.line << "]" << endl;
    }

    return 0;
}
