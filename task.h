#ifndef MAIN_HEADER
#define MAIN_HEADER


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_AMOUNT 10
#define MAX_TASK_LENGTH 64

typedef struct {
	char name[64];
	int priority;
} Task;

Task* taskArray[MAX_TASK_AMOUNT]; // Total amount of tasks loaded from the file
char line[MAX_TASK_LENGTH]; // Maximum char length of one task (including the priority number of tasks)

int taskAmount = 0; // This variable is used internally by the program while calculating the amount of tasks in the file

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
