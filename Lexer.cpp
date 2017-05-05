//
// Created by Lars on 05.05.2017.
//

#include "Lexer.h"
Lexer::Lexer() {
    SymbolTable = new std::vector<std::string>;
    TokenStream = new std::vector<Token>;
}


const void Lexer::lexFile(std::string path) const {
    return;
}

const std::vector<std::string> *Lexer::getSymbolTable() const {
    return SymbolTable;
}

const std::vector<Token> *Lexer::getTokenStream() const {
    return TokenStream;
}
