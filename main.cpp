//
// Created by Lars on 10.04.2017.
//
#include <iostream>
#include <cstring>
#include "Lexer.h"
#include "Parser.h"
void start(std::string sourcePath){
    Lexer *lex = new Lexer(sourcePath);
    std::vector<std::string> *symTab = lex->getSymbolTable();
    Parser *parser = new Parser(lex);
    parser->start();
    parser->printAST(symTab);
    std::cout << "=====================================================" << std::endl;
}
int main(int argc, char *argv[]) {
    if (argc>1) {
        start(argv[1]);
    } else {
        std::string fileName = "tmp.go";
        remove(fileName.c_str());
        std::ofstream outfile (fileName,std::ofstream::binary);
        std::string end = "end";
        std::string line = "";
        do {
            outfile.write (line.c_str(),line.size());
            std::getline(std::cin, line);
        } while(end.compare(line));
        outfile.close();
        start(fileName);
        remove(fileName.c_str());
    }

    return 0;
}
