
all:
	clang src/Main.c -o ./Main -I ./include -L ./lib/SDL2 -l SDL2

