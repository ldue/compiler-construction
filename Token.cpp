//
// Created by Lars on 05.05.2017.
//

#include "Token.h"


Token::Token(tok type) : type(type) {}
Token::Token(tok type, int tableIndex) : tableIndex(tableIndex), type(type) {}

