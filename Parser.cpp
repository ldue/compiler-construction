//
// Created by Naschinsui on 07.05.2017.
//

#include "Parser.h"

Parser::Parser(Lexer *lex) : lex(lex), curToken(Token(tok_err)), astTree(new st_tree::tree<AST_Node>), err(false) {

}

st_tree::tree<AST_Node> *Parser::getAstTree() const {
    return astTree;
}

void Parser::printAST() {
    typedef st_tree::tree<AST_Node>::df_pre_iterator iterator;
    std::vector<std::string> *symTab = lex->getSymbolTable();
    for (iterator j(astTree->df_pre_begin()); j != astTree->df_pre_end(); ++j) {
        // data() gives the data 'payload' of the node
        AST_Node data = j->data();

        // ply() gives the ply, or layer, of the node
        unsigned int ply = j->ply();

        // padding for nice output
        unsigned int w = 16;
        unsigned int padL = ply * 4;
        unsigned int padR = w - data.getValue().size() - padL;

        std::cout << indent(padL);
        std::cout << data.getValue();
        std::cout << indent(padR);
        if (data.getSymbolTableIndex() != -1) {
            std::cout << data.getSymbolTableIndex() << " : " << (*symTab)[data.getSymbolTableIndex()];
        }
        // is_root() is true if the node has no parent
        // parent() returns the node's parent
        // std::cout << "   parent= " << ((j->is_root()) ? "       " : j->parent().data().getValue());

        // ply() gives the ply, or layer, of the node
        // std::cout << "   ply= " << j->ply();

        // depth() is the depth of the node's subtree
        // std::cout << "   depth= " << j->depth();

        // subtree_size() is the size of the node's subtree
        // std::cout << "   subtree_size= " << j->subtree_size();
        std::cout << "\n";
    }
}

const char *Parser::indent(unsigned int n) {
    static char const spaces[] = "                                             ";
    static const unsigned ns = sizeof(spaces) / sizeof(*spaces);
    return spaces + (ns - 1 - n);
}

void Parser::printError(Token tok) {
    std::cout << "Syntax Error: Expected " << tok.getTokenName() << ", but got " << curToken.getTokenName()
              << std::endl;
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
    astTree->insert(AST_Node("Root ->"));
    node_iterator child = astTree->root().insert(AST_Node("SourceFile ->"));
    packageClause(child);
    importClause(child);
}

void Parser::packageClause(Parser::node_iterator parent) {
    node_iterator child = parent->insert(AST_Node("PackageClause ->"));
    if (curToken.getType() == tok_package) {
        child->insert(AST_Node(curToken));
        advTok();
        if (curToken.getType() == tok_id) {
            child->insert(AST_Node(curToken));
            advTok();
            if (curToken.getType() == tok_semicolon) {
                child->insert(AST_Node(curToken));
                advTok();
                return;
            }
            printError(Token(tok_semicolon));
        }
        printError(Token(tok_id));
    }
    printError(Token(tok_package));
}

void Parser::importClause(Parser::node_iterator parent) {
    if (curToken.getType() == tok_import) {
        node_iterator child = parent->insert(AST_Node("ImportClause ->"));
        child->insert(AST_Node(curToken));
        advTok();
        switch (curToken.getType()) {
            case tok_parL: {
                child->insert(AST_Node(curToken));
                advTok();
                importListEntry(child);
                if(curToken.getType() == tok_parR){
                    child->insert(AST_Node(curToken));
                    advTok();
                    return;
                }
                printError(Token(tok_parR));
                return;
            }
            case tok_litString: {
                child->insert(AST_Node(curToken));
                advTok();
                if (curToken.getType() == tok_semicolon) {
                    child->insert(AST_Node(curToken));
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

void Parser::importListEntry(Parser::node_iterator parent) {
    node_iterator child = parent->insert(AST_Node("ImportListEntry ->"));
    if (curToken.getType() == tok_litString) {
        child->insert(AST_Node(curToken));
        advTok();
        if(curToken.getType() == tok_semicolon){
            child->insert(AST_Node(curToken));
            advTok();
            importListEntry((parent));
            return;
        }
        printError(Token(tok_semicolon));
    }
    return;
}
