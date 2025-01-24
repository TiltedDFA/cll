SOURCES=(main.cpp string.hpp vector.hpp array.hpp algorithm.hpp types.hpp)
g++ $SOURCES -o testdbg -O0 -Wall -Wpedantic -Wextra -ggdb
g++ $SOURCES -o testrel -O3
