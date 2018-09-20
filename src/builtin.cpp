#include "../include/builtin.hpp"

extern char* builtin_names[] = {
	"cd",
	"pwd",
	"logout",
	"ls"
};

extern int (*builtin[])(char**) = {
	cd,
	pwd,
	logout,
	ls
};

int builtins(){
	return sizeof (builtin_names) / sizeof(char*);
}

int cd (char** args) {
    if(args[1] != nullptr) return chdir(args[1]);
    else return chdir(getpwuid(getuid())->pw_dir);
}

int ls (char** args){

	char buff[FILENAME_MAX];
	getcwd(buff, FILENAME_MAX);

	for (auto i : fs::directory_iterator(buff)){
        if (i.path().filename().string()[0] == '.') continue;
		if (args[1] != nullptr)
		    if (!strcmp(args[1], "--color"))
                if (fs::is_directory(i.path())) std::cout << fg(blue);
                else if (
                    ((fs::status(i).permissions() & fs::perms::owner_exec) != fs::perms::none) ||
                    ((fs::status(i).permissions() & fs::perms::group_exec) != fs::perms::none) ||
                    ((fs::status(i).permissions() & fs::perms::others_exec) != fs::perms::none )) std::cout << fg(green);
		std::cout << i.path().filename().string() << reset_prompt() << "  ";
	}

	std::cout << std::endl;
	return 0;
}

int pwd (char**) {

	std::cout << fs::current_path().string() << std::endl;

	return 0;
}

int logout (char**) {
	std::cout << "Bye\n";
	exit (EXIT_SUCCESS);
}
