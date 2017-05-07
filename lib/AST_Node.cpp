//
// Created by Naschinsui on 07.05.2017.
//

#include <iostream>
#include "AST_Node.h"



void AST_Node::insertChild(AST_Node *child) {
    children->push_back(child);
}

const std::string &AST_Node::getValue() const {
    return value;
}

int AST_Node::getSymbolTableIndex() const {
    return symbolTableIndex;
}

const std::vector<AST_Node *>* AST_Node::getChildren() const {
    return children;
}

AST_Node *AST_Node::getParent() const {
    return parent;
}

AST_Node::AST_Node(const std::string &value, int symbolTableIndex, AST_Node *parent) : value(value), symbolTableIndex(
        symbolTableIndex), parent(parent) {
    children = new std::vector<AST_Node*>;
}

AST_Node::AST_Node(const std::string &value, AST_Node *parent) : value(value), symbolTableIndex(
        -1), parent(parent) {
    children = new std::vector<AST_Node*>;
}

AST_Node::AST_Node(Token tok, AST_Node *parent) {
    children = new std::vector<AST_Node*>;
    value = tok.getTokenName();
    symbolTableIndex = tok.getTableIndex();
}

void AST_Node::print(int depth, std::vector<std::string>* symTab) {
    for(int i = 0; i<depth;i++){
        std::cout<<"\t";
    }
    std::cout<<value<<" ";
    if(symbolTableIndex != -1){
        std::cout << symbolTableIndex << " : " << (*symTab)[symbolTableIndex];
    }
    std::cout<<std::endl;
    for(auto c = children->begin(); c != children->end(); ++c){
        (*c)->print(depth+1, symTab);
    }
}
