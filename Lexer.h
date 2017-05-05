//
// Created by Lars on 05.05.2017.
//

#include "vector"
#include "string"
#include "Token.h"

#ifndef COMPILER_CONSTRUCTION_LEXER_H
#define COMPILER_CONSTRUCTION_LEXER_H


class Lexer {
private:
    std::vector<std::string>* SymbolTable;
    std::vector<Token>* TokenStream;
public:
    Lexer();

    const void lexFile (std::string path) const;

    const std::vector<std::string>* getSymbolTable() const;

    const std::vector<Token>* getTokenStream() const;
};


#endif //COMPILER_CONSTRUCTION_LEXER_H
