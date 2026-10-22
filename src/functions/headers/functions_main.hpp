#ifndef FUNCTIONS_MAIN_HPP
#define FUNCTIONS_MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../classes_objects/headers/global_objects.hpp"
#include "../../classes_objects/headers/classes.hpp"

namespace funcMain
{
    string clainUnderlineBar();

    string pressEnter();

    void dataConversor(string&, Data);

    void contactConversor(string&, int, int);
}

#endif