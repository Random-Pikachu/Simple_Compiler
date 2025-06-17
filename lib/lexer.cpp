#include "../headers/lexer.h"
#include <bits/stdc++.h>
#include <cctype>

using namespace std;
Lexer::Lexer(const string& source): source(source), pos(0), line(1) {}

vector<Token> Lexer::tokenize() {
    vector<Token> tokens;

    while(pos < source.size()){

        skipWhitespaceandComments();
        if (pos >= source.size()) break;

        string word = readWord();
        if (word.empty()) continue;

        if (isInstruction(word)) {
            tokens.push_back({TokenType::INSTRUCTION, word, line});
        }
        else if (isNumber(word)) {
            tokens.push_back({TokenType::NUMBER, word, line});
        }
        else {
            throw runtime_error("Line " + to_string(line) + ": unrecognized token '" + word + "'");
        }
    }

    tokens.push_back({TokenType::END, "", line});
    return tokens;
}

void Lexer::skipWhitespaceandComments(){
    while(pos < source.size()){
        char ch = source[pos];

        if (ch == '\n') {
            line++;
            pos++;
        }
        else if (ch == ' ' || ch == '\t' || ch == '\r') pos++;
        else if (ch == '#') {
            while(pos < source.size() && source[pos] != '\n') pos++;
        }
        else break;
    }
}

string Lexer::readWord(){
    size_t start = pos;
    while (pos < source.size() && source[pos] != ' ' && source[pos] != '\t' && source[pos] != '\r' && source[pos] != '\n' && source[pos] != '#') pos++;
    return source.substr(start, pos - start);
}

bool Lexer::isInstruction(string& word){
    static const set<string> instructions = {
        "push", "pop", "add", "sub", "mul", "div",
        "print", "dup", "swap", "halt"
    };
    return instructions.count(word) > 0;
}

bool Lexer::isNumber(string& word){
    if (word.empty()) return false;

    size_t start = 0;
    if (word[0] == '-'){
        start = 1;
        if (word.size() == 1) return false;
    }

    for (size_t i = start; i < word.size(); i++){
        if(!isdigit(word[i])) return false;
    }

    return true;
}