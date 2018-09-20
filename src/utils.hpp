#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <experimental/filesystem>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

char *convert(const std::string & s);
std::vector<char*> split_string(std::string string, std::string delimiter);
std::string pretty_cwd();

#endif