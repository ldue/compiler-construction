//
// Created by Lars on 05.05.2017.
//
#include "string"

#ifndef COMPILER_CONSTRUCTION_TOKEN_H
#define COMPILER_CONSTRUCTION_TOKEN_H

enum tok {
    tok_err = -1,
    tok_eof = 0,


    //keywords
    tok_break = 1,
    tok_default = 2,
    tok_interface = 3,
    tok_select = 4,
    tok_case = 5,
    tok_defer = 6,
    tok_go = 7,
    tok_map = 8,
    tok_struct = 9,
    tok_chan = 10,
    tok_else = 11,
    tok_goto = 12,
    tok_package = 13,
    tok_switch = 14,
    tok_const = 15,
    tok_fallthrough = 16,
    tok_if = 17,
    tok_range = 18,
    tok_type = 19,
    tok_continue = 20,
    tok_for = 21,
    tok_import = 22,
    tok_return = 23,
    tok_var = 24,
    tok_func = 25,

    //parentheses
    tok_parL = 26, //(
    tok_parR = 27, //)
    tok_braL = 28, //[
    tok_braR = 29, //]
    tok_curL = 30, //{
    tok_curR = 31, //}

    //other operators
    tok_plus = 32,
    tok_minus = 33,
    tok_mul = 34,
    tok_div = 35,
    tok_mod = 36,
    tok_binAnd = 37,
    tok_binOr = 38,
    tok_binXor = 39,
    tok_siftL = 40,
    tok_shiftR = 41,
    tok_binClear = 42,
    tok_plusEq = 43,
    tok_minusEq = 44,
    tok_mulEq = 45,
    tok_divEq = 46,
    tok_modEq = 47,
    tok_binAndEq = 48,
    tok_binOrEq = 49,
    tok_binXorEq = 50,
    tok_siftLEq = 51,
    tok_shiftREq = 52,
    tok_binClearEq = 53,
    tok_logAnd = 54,
    tok_logOr = 55,
    tok_chanOp = 56,
    tok_incr = 57,
    tok_decr = 58,
    tok_logEq = 59,
    tok_greater = 60,
    tok_less = 61,
    tok_equals = 62,
    tok_not = 63,
    tok_notEq = 64,
    tok_lessEq = 65,
    tok_greaterEq = 66,
    tok_declEq = 67,
    tok_dotdotdot = 68,
    tok_colon = 69,
    tok_semicolon = 70,
    tok_dot = 71,
    tok_comma = 72,

    tok_id = 73,

    tok_litInt = 74,
    tok_litFloat = 75,
    tok_litRune = 76,
    tok_litString = 77,
    tok_litBool = 78,

    tok_TypeInt = 79,
    tok_TypeFloat = 80,
    tok_TypeRune = 81,
    tok_TypeString = 82,
    tok_TypeBool = 83,
};
class Token {
private:
    int tableIndex;
    tok type;

public:
    Token(tok type);
    Token(tok type,int TableIndex);

    tok getType() const;

    int getTableIndex() const;

    std::string getTokenName();
};


#endif //COMPILER_CONSTRUCTION_TOKEN_H
