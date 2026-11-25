all: todo

todo: main.c task.c task.h
	gcc main.c -o todo -Wextra -O2 -flto

install: todo
	cp ./todo /usr/local/bin/
clean:
	rm -f todo
