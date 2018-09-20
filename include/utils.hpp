#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <experimental/filesystem>
#include <sys/types.h>
#include <pwd.h>
#include <wait.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

char *convert(const std::string & s);
char** split_string(std::string string, std::string delimiter);
std::string pretty_cwd();
int launch(char**);

#endif