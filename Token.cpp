//
// Created by Lars on 05.05.2017.
//

#include <iostream>
#include "Token.h"


Token::Token(tok type) : type(type) {}
Token::Token(tok type, int tableIndex) : tableIndex(tableIndex), type(type) {}


tok Token::getType() const {
    return type;
}

int Token::getTableIndex() const {
    return tableIndex;
}

std::string Token::getTokenName() {
    int t = (int) type;
    switch (t) {
        case -1 : return "ERROR";
        case 0 : return "EOF";
        case 1 : return "KEYWORD BREAK";
        case 2 : return "KEYWORD DEFAULT";
        case 3 : return "KEYWORD INTERFACE";
        case 4 : return "KEYWORD SELECT";
        case 5 : return "KEYWORD CASE";
        case 6 : return "KEYWORD DEFER";
        case 7 : return "KEYWORD GO";
        case 8 : return "KEYWORD MAP";
        case 9 : return "KEYWORD STRUCT";
        case 10 : return "KEYWORD CHAN";
        case 11 : return "KEYWORD ELSE";
        case 12 : return "KEYWORD GOTO";
        case 13 : return "KEYWORD PACKAGE";
        case 14 : return "KEYWORD SWITCH";
        case 15 : return "KEYWORD CONST";
        case 16 : return "KEYWORD FALLTHORUGH";
        case 17 : return "KEYWORD IF";
        case 18 : return "KEYWORD RANGE";
        case 19 : return "KEYWORD TYPE";
        case 20 : return "KEYWORD CONTINUE";
        case 21 : return "KEYWORD for";
        case 22 : return "KEYWORD IMPORT";
        case 23 : return "KEYWORD return";
        case 24 : return "KEYWORD var";
        case 25 : return "KEYWORD func";

        case 26 : return "(";
        case 27 : return ")";
        case 28 : return "[";
        case 29 : return "]";
        case 30 : return "{";
        case 31 : return "}";
        case 32 : return "+";
        case 33 : return "-";
        case 34 : return "*";
        case 35 : return "/";
        case 36 : return "%";
        case 37 : return "&";
        case 38 : return "|";
        case 39 : return "^";
        case 40 : return "<<";
        case 41 : return ">>";
        case 42 : return "&^";
        case 43 : return "+=";
        case 44 : return "-=";
        case 45 : return "*=";
        case 46 : return "/=";
        case 47 : return "%=";
        case 48 : return "";
        case 49 : return "";
        case 50 : return "";
        case 51 : return "";
        case 52 : return "";
        case 53 : return "";
        case 54 : return "";
        case 55 : return "";
        case 56 : return "";
        case 57 : return "++";
        case 58 : return "--";
        case 59 : return "==";
        case 60 : return "";
        case 61 : return "";
        case 62 : return "=";

        case 70 : return "SEMICOLON";
        case 71 : return "FUNC CALL";
        case 72 : return "COMMA";
        case 73 : return "id";
        case 74 : return "LITERAL INT";
        case 75 : return "LITERAL FLOAT";
        case 76 : return "LITERAL RUNE";
        case 77 : return "LITERAL STRING";
        case 78 : return "LITERAL BOOL";
    }
}
