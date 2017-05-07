//
// Created by Naschinsui on 07.05.2017.
//

#include "Parser.h"

Parser::Parser(Lexer *lex) : lex(lex), nextToken(Token(tok_err)), astTree(new st_tree::tree<AST_Node>) {

}

st_tree::tree<AST_Node> *Parser::getAstTree() const {
    return astTree;
}

void Parser::printAST() {
    typedef st_tree::tree<AST_Node>::df_pre_iterator iterator;
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

        // is_root() is true if the node has no parent
        // parent() returns the node's parent
        std::cout << "   parent= " << ((j->is_root()) ? "       " : j->parent().data().getValue());

        // ply() gives the ply, or layer, of the node
        std::cout << "   ply= " << j->ply();

        // depth() is the depth of the node's subtree
        std::cout << "   depth= " << j->depth();

        // subtree_size() is the size of the node's subtree
        std::cout << "   subtree_size= " << j->subtree_size();
        std::cout << "\n";
    }
}

const char *Parser::indent(unsigned int n) {
    static char const spaces[] = "                                             ";
    static const unsigned ns = sizeof(spaces) / sizeof(*spaces);
    return spaces + (ns - 1 - n);
}

void Parser::start() {
    sourceFile();
}
void Parser::sourceFile() {
    astTree->insert(AST_Node("Root ->"));
    node_iterator child = astTree->root().insert(AST_Node("SourceFile ->"));
    packageClause(child);
}

void Parser::packageClause(Parser::node_iterator parent) {
    parent->insert(AST_Node("PackageClause"));
}
