#include "builtin.hpp"

extern char* builtin_names[] = {
	"cd",
	"pwd",
	"logout",
	"ls"
};

extern int (*builtin[])(std::vector<char*>) = {
	cd,
	pwd,
	logout,
	ls
};

int builtins(){
	return sizeof (builtin_names) / sizeof(char*);
}

int cd (std::vector<char*> args) {
    if(!args.empty()) return chdir(args[0]);
    else return chdir(getpwuid(getuid())->pw_dir);
}

int ls (std::vector<char*> args){

	char buff[FILENAME_MAX];
	getcwd(buff, FILENAME_MAX);

	for (auto i : fs::directory_iterator(buff)){
        if (i.path().filename().string()[0] == '.') continue;
		if (!args.empty())
		    if (!strcmp(args[0], "--color"))
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

int pwd (std::vector<char*>) {

	std::cout << fs::current_path().string() << std::endl;

	return 0;
}

int logout (std::vector<char*>) {
	std::cout << "Bye\n";
	exit (EXIT_SUCCESS);
}
