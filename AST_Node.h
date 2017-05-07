//
// Created by Naschinsui on 07.05.2017.
//

#ifndef COMPILER_CONSTRUCTION_AST_NODE_H
#define COMPILER_CONSTRUCTION_AST_NODE_H

#include "string"
#include "Token.h"
class AST_Node {
private:
    std::string value;
    int symbolTableIndex;
public:
    AST_Node(Token token);
    AST_Node(const std::string &value, int symbolTableIndex);
    AST_Node(const std::string &value);
    AST_Node();
    const std::string &getValue() const;
    int getSymbolTableIndex() const;
};


#endif //COMPILER_CONSTRUCTION_AST_NODE_H
