//
// Created by Naschinsui on 07.05.2017.
//

#include "AST_Node.h"

AST_Node::AST_Node(const std::string &value) : value(value), symbolTableIndex(-1) {}

AST_Node::AST_Node(const std::string &value, int symbolTableIndex) : value(value), symbolTableIndex(symbolTableIndex) {}

AST_Node::AST_Node() :  value(""), symbolTableIndex(-1){}

AST_Node::AST_Node(Token token) {
    this->value = token.getTokenName();
    if(token.getTableIndex()!= -1){
        this->symbolTableIndex = token.getTableIndex();
    } else {
        this->symbolTableIndex = -1;
    }
}

const std::string &AST_Node::getValue() const {
    return value;
}

int AST_Node::getSymbolTableIndex() const {
    return symbolTableIndex;
}
