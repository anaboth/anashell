all:
	clang++-6.0 src/anash.cpp  src/builtin.cpp src/utils.cpp src/colors.cpp -std=c++17 -lstdc++fs -o anashell

clean:
	rm anashell