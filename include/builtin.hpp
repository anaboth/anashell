#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include <vector>
#include <iostream>
#include <unistd.h>
#include "colors.hpp"
#include <experimental/filesystem>
#include <cstring>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <iomanip>

namespace fs = std::experimental::filesystem;

int cd (char**);
int ls (char**);
int pwd (char**);
int logout (char**);

extern char* builtin_names[];

extern int (*builtin[])(char**);

int builtins();

#endif