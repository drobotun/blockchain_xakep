#ifndef STRIBOG_H
#define STRIBOG_H

#include <iostream>
#include <sstream>

#include "gost_3411_2012/gost_3411_2012_calc.h"

#define HASH_SIZE 256

std::string get_hash_stribog(std::string str);

#endif // STRIBOG_H
