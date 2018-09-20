#include "../include/colors.hpp"
#include "../include/builtin.hpp"
#include "../include/utils.hpp"

int main(int argc, char** argv){
	char hostname[64];
	
	struct passwd* user = getpwuid(getuid());
	gethostname(hostname, 64);

	while(true){
		char** args = {nullptr};
		std::string line;
		std::cout << fg(red) << user->pw_name << "@" << hostname << " " << pretty_cwd() << " > " << reset_prompt();
		std::getline(std::cin, line);
		
		args = split_string(line, " ");

		// int i = 0;
		// while(args[i] != nullptr) {
		// 	printf("\"%s\"\n", args[i]);
		// 	i++;
		// }

		bool control = false;
		for (int i = 0; i < builtins(); i++){
			if(!strcmp(args[0], builtin_names[i])){
				builtin[i](args);
				control = true;
			}
		}

		if (!control)
			if (launch(args) == -1) perror("Launcher error");
	}

	return 0;
}
