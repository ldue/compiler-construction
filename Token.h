//
// Created by Lars on 05.05.2017.
//
#include "string"

#ifndef COMPILER_CONSTRUCTION_TOKEN_H
#define COMPILER_CONSTRUCTION_TOKEN_H

typedef enum tok {
    tok_eof,

    //keywords
    tok_break,
    tok_default,
    tok_interface,
    tok_select,
    tok_case,
    tok_defer,
    tok_go,
    tok_map,
    tok_struct,
    tok_chan,
    tok_else,
    tok_goto,
    tok_package,
    tok_switch,
    tok_const,
    tok_fallthrough,
    tok_if,
    tok_range,
    tok_type,
    tok_continue,
    tok_for,
    tok_import,
    tok_return,
    tok_var,
    tok_func,

    //parentheses
    tok_parL, //(
    tok_parR, //)
    tok_braL, //[
    tok_braR, //]
    tok_curL, //{
    tok_curR, //}

    //other operators
    tok_plus,
    tok_minus,
    tok_mul,
    tok_div,
    tok_mod,
    tok_binAnd,
    tok_binOr,
    tok_binXor,
    tok_siftL,
    tok_shiftR,
    tok_binClear,
    tok_plusEq,
    tok_minusEq,
    tok_mulEq,
    tok_divEq,
    tok_modEq,
    tok_binAndEq,
    tok_binOrEq,
    tok_binXorEq,
    tok_siftLEq,
    tok_shiftREq,
    tok_binClearEq,
    tok_logAnd,
    tok_logOr,
    tok_chanOp,
    tok_incr,
    tok_decr,
    tok_logEq,
    tok_greater,
    tok_less,
    tok_equals,
    tok_not,
    tok_notEq,
    tok_lessEq,
    tok_greaterEq,
    tok_declEq,
    tok_dotdotdot,
    tok_colon,
    tok_semicolon,
    tok_dot,
    tok_comma,
    tok_id,

    tok_litInt,
    tok_litFloat,
    tok_litRune,
    tok_litString,
    tok_litBool,

    tok_TypeInt,
    tok_TypeFloat,
    tok_TypeRune,
    tok_TypeString,
    tok_TypeBool
};
class Token {
private:
    int tableIndex;
    tok type;
public:
    Token(tok type);
    Token(tok type,int TbleIndex);
};


#endif //COMPILER_CONSTRUCTION_TOKEN_H
