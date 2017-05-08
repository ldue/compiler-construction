//
// Created by Lars on 10.04.2017.
//
#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    //"/cygdrive/c/Users/Naschinsui/CLionProjects/compiler-construction/test/samplefiles/"
    if (argc) {
        Lexer *lex = new Lexer(argv[1]);
        std::vector<std::string> *symTab = lex->getSymbolTable();
        Parser *parser = new Parser(lex);
        parser->start();
        parser->printAST(symTab);
        std::cout << "=====================================================" << std::endl;
    } else {
        std::string line= "";
        std::cin>> line;
    }
    /*do {
        curTok = lex->getNextTok();
        std::cout << "TOK " << curTok.getTokenName();
        if(curTok.getType()== tok_id || curTok.getType()== tok_litString || curTok.getType()== tok_litBool){
            int index = curTok.getTableIndex();
            std::string tmp = (*symTab)[index];
            std::cout <<index<< " " << tmp;
        }
        std::cout << std::endl;
    } while ( (curTok.getType() != tok_err) && (curTok.getType() != tok_eof) );
    std::cout << "TOK " << symTab->size() << std::endl;*/
    return 0;
}