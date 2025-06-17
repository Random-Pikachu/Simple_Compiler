#pragma once
#include <string>
#include <vector>
using namespace std;

enum class TokenType {
    INSTRUCTION,
    NUMBER,
    END,
};

struct Token {
    TokenType type;
    string value;
    int line;
};

class Lexer {
    public:
        Lexer(const string& source);
        vector<Token> tokenize();
    
    private:
        string source;
        size_t pos;
        int line;

        void skipWhitespaceandComments();
        string readWord();
        bool isInstruction(string& word);
        bool isNumber(string& word);
};