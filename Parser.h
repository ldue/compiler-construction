//
// Created by Naschinsui on 07.05.2017.
//

#ifndef COMPILER_CONSTRUCTION_PARSER_H
#define COMPILER_CONSTRUCTION_PARSER_H

#include "Lexer.h"
#include "Token.h"
#include "lib/Tree.h"
#include "string"
#include "lib/AST_Node.h"
#include "iostream"

class Parser {

private:
    Token curToken;
    Lexer *lex;
    Tree astTree;
    bool err;

    void printError(Token tok);

    void printError(std::string err);

    void advTok();

    void sourceFile();

    void packageClause(AST_Node *parent);

    void importClause(AST_Node *parent);

    void importListEntry(AST_Node *parent);

    void topLevelDeclaration(AST_Node *parent);

    void varDeclaration(AST_Node *parent);

    void funcDeclaration(AST_Node *parent);

    void parameters(AST_Node *parent);

    void returnValues(AST_Node *parent);

    void StatementList(AST_Node *parent);

    void expression(AST_Node *parent);

    void type(AST_Node *parent);

public:
    Tree getAstTree() const;

public:
    Parser(Lexer *lex);

    void printAST(std::vector<std::string> *);

    void start();
};


#endif //COMPILER_CONSTRUCTION_PARSER_H
