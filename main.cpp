//
// Created by Lars on 10.04.2017.
//
#include <iostream>

#include "Lexer.h"
#include "Token.h"

int main () {
    Lexer* lex = new Lexer("/cygdrive/c/Users/Lars/Documents/CC/compiler-construction/test/samplefiles/testfile1_HelloWorld.go");

    Token curTok = Token(tok_err);
    do {
        curTok = lex->getNextTok();
        std::cout << curTok.getType() << std::endl;
    }while ( (curTok.getType() != tok_err) && (curTok.getType() != tok_eof) );
    return 0;
}