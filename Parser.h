//
// Created by Naschinsui on 07.05.2017.
//

#ifndef COMPILER_CONSTRUCTION_PARSER_H
#define COMPILER_CONSTRUCTION_PARSER_H

#include "Lexer.h"
#include "Token.h"
#include "lib/st_tree.h"
#include "string"
#include "AST_Node.h"
#include "iostream"

class Parser {

private:
    typedef st_tree::tree<AST_Node>::iterator iterator;
    typedef st_tree::tree<AST_Node>::node_type::iterator node_iterator;
    Token curToken;
    Lexer* lex;
    st_tree:: tree<AST_Node>* astTree;
    const char* indent(unsigned int n);
    bool err;
    void printError(Token tok);
    void advTok();
    void sourceFile();
    void packageClause (node_iterator parent);
    void importClause (node_iterator parent);
    void importListEntry (node_iterator parent);
public:
    st_tree::tree<AST_Node>* getAstTree() const;

public:
    Parser(Lexer *lex);
    void printAST();
    void start();
};


#endif //COMPILER_CONSTRUCTION_PARSER_H
