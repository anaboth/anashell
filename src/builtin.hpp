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

int cd (std::vector<char*>);
int ls (std::vector<char*>);
int pwd (std::vector<char*>);
int logout (std::vector<char*>);

extern char* builtin_names[];

extern int (*builtin[])(std::vector<char*>);

int builtins();

#endif