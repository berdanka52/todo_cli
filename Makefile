all: todo

todo: main.c task.c task.h
	clang main.c -o todo -Wextra -O3
clean:
	rm -f todo
