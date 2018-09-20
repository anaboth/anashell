#include "../include/utils.hpp"

char *convert(const std::string & s){
	char *pc = new char[s.size()+1];
	std::strcpy(pc, s.c_str());
	return pc; 
}

int launch(char* cmd, std::vector<char*> args){
	
	pid_t pid;
	pid_t wpid;
	int status;
	if (args.empty())
		args.push_back(cmd);
	else
		args.insert(args.begin(), cmd);
	if ((pid = fork()) == 0){
		if(execvp(cmd, &args[0]) == -1) exit(EXIT_FAILURE);
	} else if (pid < 0){
		perror("Fork error");
		return -1;
	} else {
		do {
			wpid = waitpid(0, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 0;
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
	string.clear();
	return ret;
}

std::string pretty_cwd(){
    std::string s = std::experimental::filesystem::current_path().string();
    if(s.find(getpwuid(getuid())->pw_dir) != std::string::npos)
        s.replace(0, std::string(getpwuid(getuid())->pw_dir).length(), "~");
    return s;
}