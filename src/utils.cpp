#include "utils.hpp"

char *convert(const std::string & s){
	char *pc = new char[s.size()+1];
	std::strcpy(pc, s.c_str());
	return pc; 
}

std::vector<char*> split_string(std::string string, std::string delimiter){
	std::vector<std::string> vec;
	std::vector<char*> ret;
	size_t pos;

	while (std::string::npos != (pos = string.find(delimiter))){
		vec.push_back(string.substr(0, pos));
		string.erase(string.begin(), string.begin() + pos + delimiter.length());
	}
	vec.push_back(string);

	std::transform(vec.begin(), vec.end(), std::back_inserter(ret), convert);

	return ret;
}

std::string pretty_cwd(){
    std::string s = std::experimental::filesystem::current_path().string();
    if(s.find(getpwuid(getuid())->pw_dir) != std::string::npos)
        s.replace(0, std::string(getpwuid(getuid())->pw_dir).length(), "~");
    return s;
}