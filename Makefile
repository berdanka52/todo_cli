all: todo

todo: main.c
	clang main.c -g -Wextra -o todo -O0
clean:
	rm -f todo
