//
// Created by Lars on 05.05.2017.
//

#include "vector"
#include "string"
#include "Token.h"
#include "fstream"

#include <iostream>

#ifndef COMPILER_CONSTRUCTION_LEXER_H
#define COMPILER_CONSTRUCTION_LEXER_H


class Lexer {
private:
    std::vector<std::string>* SymbolTable;
    std::vector<Token>* TokenStream;
    std::ifstream* srcFile;
    char curChar;

    void advCurChar();

    Token getAlphaTok();
    Token getKeyordTok(std::string keyword);

    Token getLitBoolTok(std::string keyword);
    Token getLitStrTok();
    Token getLitNumTok();

public:
    Lexer(std::string path);

    virtual ~Lexer();

    Token getNextTok();

    const std::vector<std::string>* getSymbolTable() const;

    const std::vector<Token>* getTokenStream() const;
};


#endif //COMPILER_CONSTRUCTION_LEXER_H
