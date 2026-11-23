all: todo

todo: main.c task.c task.h
	clang main.c -o todo -Wextra -O3

install: todo
	cp ./todo /usr/local/bin/
clean:
	rm -f todo
