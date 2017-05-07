//
// Created by Naschinsui on 07.05.2017.
//

#include "Tree.h"

Tree::Tree( AST_Node *root) : root(root) {}

AST_Node *Tree::getRoot() const {
    return root;
}

void Tree::printTree(std::vector<std::string>* symTab) {
    root->print(0, symTab);
}

void Tree::setRoot(AST_Node *root) {
    Tree::root = root;
}

