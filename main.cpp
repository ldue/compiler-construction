//
// Created by Lars on 10.04.2017.
//
#include <iostream>
#include <string>
#include "st_tree.h"
#include <iostream>

int main () {
    st_tree::tree<std::string> t;
    typedef st_tree::tree<std::string>::iterator iterator;
    t.insert("Hello");
    t.root().insert(" ");
    t.root().insert("World");

    for (iterator j(t.begin());  j != t.end();  ++j)
        std::cout << j->data();


    return 0;
}
