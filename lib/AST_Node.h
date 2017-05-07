//
// Created by Naschinsui on 07.05.2017.
//

#ifndef COMPILER_CONSTRUCTION_AST_NODE_H
#define COMPILER_CONSTRUCTION_AST_NODE_H

#include "string"
#include "../Token.h"
#include "vector"
class AST_Node {
private:
    std::string value;
    int symbolTableIndex;
    std::vector<AST_Node*>* children;
    AST_Node* parent;
public:
    AST_Node(const std::string &value, int symbolTableIndex, AST_Node *parent);
    AST_Node(const std::string &value, AST_Node *parent);
    const std::string &getValue() const;
    int getSymbolTableIndex() const;
    void insertChild(AST_Node* child);
    void print(int depth, std::vector<std::string>*symTab);
    const std::vector<AST_Node *> *getChildren() const;

    AST_Node *getParent() const;
};


#endif //COMPILER_CONSTRUCTION_AST_NODE_H
