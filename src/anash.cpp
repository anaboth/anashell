#include "colors.hpp"
#include "builtin.hpp"
#include "utils.hpp"

int main(int argc, char** argv){
	char* cmd;
	std::vector<char*> args;
	std::string line;
	char hostname[64];
	
	struct passwd* user = getpwuid(getuid());
	gethostname(hostname, 64);


	while(true){

		std::cout << fg(red) << user->pw_name << "@" << hostname << " " << pretty_cwd() << " > " << reset_prompt();
		std::getline(std::cin, line);

		size_t pos;
		if(std::string::npos != (pos = line.find(" "))){
			cmd = (char*) line.substr(0, pos).c_str();
			line.erase(0, pos + 1);
			args = split_string(line, " ");
		} else {
			cmd = (char*) line.c_str();
			args.erase(args.begin(), args.end());
		}

		for (int i = 0; i < builtins(); i++){
			if(!strcmp(cmd, builtin_names[i]))
				builtin[i](args);
		}
	}

	return 0;
}
