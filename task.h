#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAIN_HEADER
#define MAIN_HEADER


typedef struct {
	char name[64];
	int priority;
} Task;

Task* taskArray[10];
int taskNum = 0;
typedef enum {
	LIST, ADD, DELETE
} menu_choice;

typedef enum {
	READ, APPEND, WRITE
} file_choice;

FILE* fileUse(int file_choice);

// This func is needed to sort tasks by priorities
int comp(const void *a, const void *b);

void fileRead();

Task* askForTask();

void addTask(Task* task);
void listTasks(); 
void deleteTask(); 
#endif
