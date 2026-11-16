all: todo

todo: main.c task.c task.h
	clang main.c -o todo -Wextra -O0 -g
clean:
	rm -f todo
