//
// Created by Lars on 05.05.2017.
//


#include <cstdlib>
#include <string>
#include "Lexer.h"

Lexer::Lexer(std::string path) {
    SymbolTable = new std::vector<std::string>;
    TokenStream = new std::vector<Token>;

    srcFile = new std::ifstream(path);
    std::string line;
    if (srcFile->is_open()) {
        std::cout << "LEXER: Opened SourcFile successfully" << std::endl;
    } else {
        std::cout << "LEXER: ERROR while opening SourceFile" << std::endl;
        exit(1);
    }
}

void Lexer::advCurChar() {
    srcFile->get(curChar);
    //std::cout << "LEXER: curChar = " << curChar << std::endl;
}

Token Lexer::getAlphaTok() {
    std::string tokStr = "";
    tokStr += curChar;
    while (isalnum(srcFile->peek()) && !srcFile->eof() ) {
        advCurChar();
        tokStr += curChar;
    }
    if(srcFile->eof())
        return Token(tok_err);

    //switch keywords
    Token tmp = getKeywordTok(tokStr);
    if (tmp.getType() != tok_err)
        return tmp;

    //switch bool
    tmp = getLitBoolTok(tokStr);
    if (tmp.getType() != tok_err)
        return tmp;

    SymbolTable->push_back(tokStr);
    return Token(tok_id, SymbolTable->size()-1);

}

Token Lexer::getKeywordTok(std::string keyword) {
    //std::cout << "LEXER: keyword = " << keyword << std::endl;
    if (keyword.compare("package") == 0)
        return Token(tok_package);
    if (keyword.compare("break") == 0)
        return Token(tok_break);
    if (keyword.compare("default") == 0)
        return Token(tok_default);
    if (keyword.compare("interface") == 0)
        return Token(tok_interface);
    if (keyword.compare("select") == 0)
        return Token(tok_select);
    if (keyword.compare("case") == 0)
        return Token(tok_case);
    if (keyword.compare("defer") == 0)
        return Token(tok_defer);
    if (keyword.compare("go") == 0)
        return Token(tok_go);
    if (keyword.compare("map") == 0)
        return Token(tok_map);
    if (keyword.compare("struct") == 0)
        return Token(tok_struct);
    if (keyword.compare("chan") == 0)
        return Token(tok_chan);
    if (keyword.compare("else") == 0)
        return Token(tok_else);
    if (keyword.compare("goto") == 0)
        return Token(tok_goto);
    if (keyword.compare("switch") == 0)
        return Token(tok_switch);
    if (keyword.compare("const") == 0)
        return Token(tok_const);
    if (keyword.compare("fallthrough") == 0)
        return Token(tok_fallthrough);
    if (keyword.compare("if") == 0)
        return Token(tok_if);
    if (keyword.compare("range") == 0)
        return Token(tok_range);
    if (keyword.compare("type") == 0)
        return Token(tok_type);
    if (keyword.compare("continue") == 0)
        return Token(tok_continue);
    if (keyword.compare("for") == 0)
        return Token(tok_for);
    if (keyword.compare("import") == 0)
        return Token(tok_import);
    if (keyword.compare("return") == 0)
       return Token(tok_return);
    if (keyword.compare("var") == 0)
        return Token(tok_var);
    if (keyword.compare("func") == 0)
        return Token(tok_func);
    return Token(tok_err);
}

Token Lexer::getLitBoolTok(std::string keyword) {
    if ( (keyword.compare("true") == 0) || (keyword.compare("false") == 0) ) {
        SymbolTable->push_back(keyword);
        return Token(tok_litBool, SymbolTable->size()-1);
    } else
        return Token(tok_err);
}

Token Lexer::getLitStrTok() {
    std::string tokStr = "";
    advCurChar();
    while ( (curChar != '\"') && (curChar != EOF) ) {
        tokStr += curChar;
        advCurChar();
    }
    if(curChar == EOF)
        return Token(tok_err);

    SymbolTable->push_back(tokStr);
    return Token(tok_litString, SymbolTable->size()-1);
}

Token Lexer::skipCommentTok() {
    if(srcFile->eof())
        return Token(tok_eof);

    switch(curChar) {
        case '/': { //Single Line Comment
            do {
                advCurChar();
            } while ( (curChar != '\0') && !srcFile->eof()); // not newline
            return getNextTok();
        }
        case '*': { //Multi Line Comment
            do {
                advCurChar();
            } while ( (curChar == '*') && (srcFile->peek() == '/')); // not */
            return getNextTok();
        }
    }
    return Token(tok_err);
}


Token Lexer::getNextTok() {
    advCurChar();
    if (srcFile->eof())
        return Token(tok_eof);


    if (isspace(curChar))
        return this->getNextTok();

    if (isalpha(curChar))// identifier: [a-zA-Z][a-zA-Z0-9]*
        return this->getAlphaTok();

    switch(curChar){
        case '\"': return getLitStrTok();
        case '(': return Token(tok_parL);
        case ')': return Token(tok_parR);
        case '[': return Token(tok_braL);
        case ']': return Token(tok_braR);
        case '{': return Token(tok_curL);
        case '}': return Token(tok_curR);
        case '.': {
            if(srcFile->peek() != '.')
                return Token(tok_dot);
        };
        case '/': return skipCommentTok();
        }

    return Token(tok_err);
}

std::vector<std::string> *Lexer::getSymbolTable() const {
    return SymbolTable;
}

const std::vector<Token> *Lexer::getTokenStream() const {
    return TokenStream;
}

Lexer::~Lexer() {
    srcFile->close();
    delete srcFile;
    delete SymbolTable;
    delete TokenStream;
}
