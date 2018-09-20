#include "../include/colors.hpp"
#include "../include/builtin.hpp"
#include "../include/utils.hpp"

int main(int argc, char** argv){
	char hostname[64];
	
	struct passwd* user = getpwuid(getuid());
	gethostname(hostname, 64);

	while(true){
		char* cmd;
		std::vector<char*> args;
		std::string line;
		std::cout << fg(red) << user->pw_name << "@" << hostname << " " << pretty_cwd() << " > " << reset_prompt();
		std::getline(std::cin, line);
		
		size_t pos;
		if(std::string::npos != (pos = line.find(" "))){
			cmd = (char*) line.substr(0, pos).c_str();
			line.erase(0, pos + 1);
			args = split_string(line, " ");
		} else {
			cmd = (char*) line.c_str();
		}

		bool control = false;
		for (int i = 0; i < builtins(); i++){
			if(!strcmp(cmd, builtin_names[i])){
				builtin[i](args);
				control = true;
			}
		}

		if (!control)
			if (launch(cmd, args) == -1) perror("Launcher error");
	}

	return 0;
}
