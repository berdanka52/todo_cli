all: todo

todo: main.c
	clang main.c -o todo -Wextra -O3
clean:
	rm -f todo
