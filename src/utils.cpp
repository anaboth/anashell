#include "../include/utils.hpp"

char *convert(const std::string & s){
	char *pc = new char[s.size()+1];
	std::strcpy(pc, s.c_str());
	return pc; 
}

int launch(char** args){
	
	pid_t pid;
	pid_t wpid;
	int status;

	if ((pid = fork()) == 0){
		if(execvp(args[0], args) == -1) exit(EXIT_FAILURE);
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

char** split_string(std::string string, std::string delimiter){
	int bufsize = 16;
	char** arr = (char**)malloc(bufsize * sizeof(char*));

	int i = 0;
	size_t pos;
	while(std::string::npos != (pos = string.find(delimiter))){
		if(i > bufsize){
			bufsize+=bufsize;
			arr = (char**)realloc(arr, bufsize * sizeof(char*));
		}
		arr[i] = (char*)malloc(string.substr(0, pos).length() * sizeof(char) + 2);
		strcpy(arr[i], (char*)string.substr(0, pos).c_str());
		string.erase(0, pos + delimiter.length());
		i++;
		// printf("%d\n",i);
	}
	arr[i] = (char*)malloc(string.length() * sizeof(char));
	strcpy(arr[i], (char*)string.c_str());
	arr[++i] = nullptr;

	return arr;
}

std::string pretty_cwd(){
    std::string s = std::experimental::filesystem::current_path().string();
    if(s.find(getpwuid(getuid())->pw_dir) != std::string::npos)
        s.replace(0, std::string(getpwuid(getuid())->pw_dir).length(), "~");
    return s;
}