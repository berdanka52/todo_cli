#include "task.h"
#include "task.c"
/* 
Current TODO list (ironic haha)

1. Add creating task file
2. Add condition if that file exists
3. Add tasks to file
4. Read tasks to file
*/

int main(int argc, char* argv[]) {

	if (argc <=1 ) {
		fileRead();
		listTasks();
		return 0;

	} else if (!(strcmp(argv[1], "-l"))) {
		fileRead();
		listTasks();
		return 0;

    } else if (!(strcmp(argv[1], "-a"))) {
		Task* taskCreated = askForTask();
		addTask(taskCreated);

    } else if (!(strcmp(argv[1], "-d"))) {
		fileRead();
		deleteTasks();
	}
  	
	return 0;
}
