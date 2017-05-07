//
// Created by Naschinsui on 07.05.2017.
//

#include "Parser.h"

Parser::Parser(Lexer *lex) : lex(lex), curToken(Token(tok_err)), astTree(Tree(nullptr)), err(false) {

}

Tree Parser::getAstTree() const {
    return astTree;
}

void Parser::printAST(std::vector<std::string> *symTab) {
    astTree.printTree(symTab);
}

void Parser::printError(Token tok) {
    std::cout << "Syntax Error: Expected " << tok.getTokenName() << ", but got " << curToken.getTokenName()
              << std::endl;
    err = true;
}

void Parser::printError(std::string err) {
    std::cout << "Syntax Error: " << err << std::endl;
    err = true;
}

void Parser::start() {
    curToken = lex->getNextTok();
    sourceFile();
}

void Parser::advTok() {
    curToken = lex->getNextTok();
    if (curToken.getType() == tok_err) {
        std::cout << "Lexer Error" << std::endl;
        exit(1);
    }
    if (curToken.getType() == tok_eof) {
        std::cout << "EOF" << std::endl;
    }
    if (err) {
        exit(1);
    }
}

void Parser::sourceFile() {
    astTree.setRoot(new AST_Node("Root->", -1, nullptr));
    AST_Node *child = new AST_Node("SourceFile ->", -1, astTree.getRoot());
    astTree.getRoot()->insertChild(child);
    packageClause(child);
    importClause(child);
    topLevelDeclaration(child);
    return;
}

void Parser::packageClause(AST_Node *parent) {
    AST_Node *child = new AST_Node("PackageClause ->", -1, parent);
    parent->insertChild(child);
    if (curToken.getType() == tok_package) {
        child->insertChild(new AST_Node(curToken, child));
        advTok();
        if (curToken.getType() == tok_id) {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            if (curToken.getType() == tok_semicolon) {
                child->insertChild(new AST_Node(curToken, child));
                advTok();
                return;
            }
            printError(Token(tok_semicolon));
        }
        printError(Token(tok_id));
    }
    printError(Token(tok_package));
}

void Parser::importClause(AST_Node *parent) {
    AST_Node *child = new AST_Node("ImportClause ->", -1, parent);
    parent->insertChild(child);
    if (curToken.getType() == tok_import) {
        child->insertChild(new AST_Node(curToken, child));
        advTok();
        switch (curToken.getType()) {
            case tok_parL: {
                child->insertChild(new AST_Node(curToken, child));
                advTok();
                importListEntry(child);
                if (curToken.getType() == tok_parR) {
                    child->insertChild(new AST_Node(curToken, child));
                    advTok();
                    return;
                }
                printError(Token(tok_parR));
                return;
            }
            case tok_litString: {
                child->insertChild(new AST_Node(curToken, child));
                advTok();
                if (curToken.getType() == tok_semicolon) {
                    child->insertChild(new AST_Node(curToken, child));
                    advTok();
                    importClause(parent);
                    return;
                }
                printError(Token(tok_semicolon));
                return;
            }
            default: {
                printError(Token(tok_litString));
                printError(Token(tok_parL));
                return;
            }
        }
    }
    return;
}

void Parser::importListEntry(AST_Node *parent) {
    AST_Node *child = new AST_Node("ImportListEntry ->", -1, parent);
    parent->insertChild(child);
    if (curToken.getType() == tok_litString) {
        child->insertChild(new AST_Node(curToken, child));
        advTok();
        if (curToken.getType() == tok_semicolon) {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            importListEntry((parent));
            return;
        }
        printError(Token(tok_semicolon));
    }
    return;
}

void Parser::topLevelDeclaration(AST_Node *parent) {
    AST_Node *child = new AST_Node("TopLevelDeclaration ->", -1, parent);
    parent->insertChild(child);
    switch (curToken.getType()) {
        case tok_func: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            funcDeclaration(child);
            topLevelDeclaration(parent);
            return;
        }
        case tok_var: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            varDeclaration(child);
            topLevelDeclaration(parent);
            return;
        }
        default:
            return;
    }
}

void Parser::varDeclaration(AST_Node *parent) {
    AST_Node *child = new AST_Node("VarDeclaration ->", -1, parent);
    parent->insertChild(child);
    if (curToken.getType() == tok_id) {
        child->insertChild(new AST_Node(curToken, child));
        advTok();
        type(child);
        if (curToken.getType() == tok_semicolon) {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        printError(tok_semicolon);
        return;
    }
    printError(tok_id);
    return;
}

void Parser::funcDeclaration(AST_Node *parent) {
    AST_Node *child = new AST_Node("FuncDeclaration ->", -1, parent);
    parent->insertChild(child);
    if (curToken.getType() == tok_id) {
        child->insertChild(new AST_Node(curToken, child));
        advTok();
        if (curToken.getType() == tok_parL) {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            parameters(child);
            if (curToken.getType() == tok_parR) {
                child->insertChild(new AST_Node(curToken, child));
                advTok();
                returnValues(child);
                if (curToken.getType() == tok_curL) {
                    child->insertChild(new AST_Node(curToken, child));
                    advTok();
                    StatementList(parent);
                    if (curToken.getType() == tok_curR) {
                        child->insertChild(new AST_Node(curToken, child));
                        advTok();
                        return;
                    }
                    printError(tok_curR);
                    return;
                }
                printError(tok_curL);
                return;
            }
            printError(tok_parR);
            return;
        }
        printError(tok_parL);
        return;
    }
    printError(tok_id);
    return;
}

void Parser::parameters(AST_Node *parent) {
    AST_Node *child = new AST_Node("Parameters ->", -1, parent);
    parent->insertChild(child);
    return;
}

void Parser::returnValues(AST_Node *parent) {
    AST_Node *child = new AST_Node("ReturnValues ->", -1, parent);
    parent->insertChild(child);
    return;
}

void Parser::StatementList(AST_Node *parent) {
    AST_Node *child = new AST_Node("StatementList ->", -1, parent);
    parent->insertChild(child);
    switch (curToken.getType()) {
        case tok_var: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            varDeclaration(child);
            StatementList(parent);
            return;
        }
        case tok_id : {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            expression(child);
            StatementList(parent);
            return;
        }
        default: {
            return;
        }
    }
}

void Parser::expression(AST_Node *parent) {
    return;
}

void Parser::type(AST_Node *parent) {
    AST_Node *child = new AST_Node("Type ->", -1, parent);
    parent->insertChild(child);
    switch (curToken.getType()) {
        case tok_TypeBool: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        case tok_TypeString: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        case tok_TypeFloat: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        case tok_TypeRune: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        case tok_TypeInt: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        case tok_id: {
            child->insertChild(new AST_Node(curToken, child));
            advTok();
            return;
        }
        default: {
            printError("Expected a Type after var declaration");
            return;
        }
    }
}

