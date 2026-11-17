# todo_cli

This cli command is a fast way to manage small daily tasks.

Written in C.

## Usage

`./todo` - list all daily tasks

`./todo -a` - add a task

`./todo -d`- delete a task

## Building

```
make all
```

(will add CMake later)

## Useful Information

Your tasks are stored in `~/.todo`
Currently the program only supports up to 10 tasks.

Also currently almost no error messages, so just make sure you type stuff right
