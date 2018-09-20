CPP_FILES := $(wildcard src/*.cpp)
CC_FLAGS := -std=c++17 -lstdc++fs
CC := clang++-6.0
WARNS := -w

all:
	$(CC) $(CPP_FILES) -o anashell $(CC_FLAGS) $(WARNS)

clean:
	rm anashell