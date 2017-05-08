//
// Created by Naschinsui on 07.05.2017.
//
#include "AST_Node.h"
#include "vector"
#ifndef COMPILER_CONSTRUCTION_TREE_H
#define COMPILER_CONSTRUCTION_TREE_H


class Tree {
private:
    AST_Node* root;

public:
    Tree(AST_Node *root);

    AST_Node *getRoot() const;
    void printTree(std::vector<std::string>* symTab);

    void setRoot(AST_Node *root);
};


#endif //COMPILER_CONSTRUCTION_TREE_H
