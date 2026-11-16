
FILE* fileUse(int file_choice) {
	// Here the code is checking whether the file with tasks exists. 
	// If it does it does nothing, if it doesn't it creates it.
	char fileDest[256];
	char fileName[256] = "/.todo";
	const char* originalHome = getenv("HOME");

		//Set home path
	if (originalHome == NULL) {
		printf("HOME is not set");
		strcpy(fileDest, fileName);
	} else {
		snprintf(fileDest, sizeof(fileDest), "%s", originalHome); 
		strcat(fileDest, fileName);
	}

	FILE* fptr = NULL;

	switch (file_choice) {

	case 0:
		fptr = fopen(fileDest, "r");
	break;

	case 1:
		fptr = fopen(fileDest, "a");
	break;

	case 2:
		fptr = fopen(fileDest, "w");
	break;

	default:
		printf("Supply a working file_choice to func");
	}

	return fptr;
}

int comp(const void *a, const void *b) {
	const Task *task_a = *(Task* const *)a;
	const Task *task_b = *(Task* const *)b;

    if (task_a == NULL || task_b == NULL ) {
		if (task_a == task_b) return 0;
		return task_a == NULL ? 1 : -1;
	}

	if (task_a->priority < task_b->priority) return 1;
    if (task_a->priority > task_b->priority) return -1;
    return 0;
}
void fileRead() {
	file_choice fileMode = READ;
	FILE* fptr = fileUse(fileMode);
	if (fptr == NULL) exit(1);

	char line[64];
	while(fgets(line, sizeof(line), fptr)) {

				// Check if task amount is too big
		if (taskNum >= 9) break;

		Task* ptrTask = malloc(sizeof(Task));
		if (ptrTask == NULL) exit(1);
		taskArray[taskNum] = ptrTask;

		size_t len = strlen(line) - 1;  //Make len usable so in indexes it points to the last element, null terminator		
		int taskPriority = atoi(&line[len - 1]); // Now our priority is an integer
		line[len - 1] = '\0'; // End the line before the priority so it doesn't get printed out
		
		strcpy(ptrTask->name, line);
		ptrTask->priority = taskPriority;
		++taskNum; 	
		}

	fclose(fptr);		
}

Task* askForTask() {
	Task* newTask = malloc(sizeof(*newTask));

	printf("Enter task name: ");
	char receivedName[64];
	fgets(receivedName, sizeof(receivedName), stdin);
	strcpy(newTask->name, strtok(receivedName, "\n")); //Remove newline from the string

	printf("Enter task priority(1-3): ");
	int receivedPriority;
	scanf("%d", &receivedPriority);
	newTask->priority = receivedPriority;

	return newTask;
}
void addTask(Task* task) {
	file_choice fileMode = APPEND;
	FILE *fptr = fileUse(fileMode);

	fprintf(fptr, "%s", task->name);
	fprintf(fptr, "%d", task->priority);
	fprintf(fptr, "\n");
	
	free(task);
	fclose(fptr);
}
void listTasks() {
	int arrayLength = sizeof(taskArray) / sizeof(taskArray[0]);
		
	qsort(taskArray, taskNum, sizeof(taskArray[0]), comp);
		
	for (int i = 0; i < arrayLength; i++) {
		if (taskArray[i] == NULL) continue;
		printf("---------------------\n");
		printf("Task name: %s\n", taskArray[i]->name);
		printf("Task priority: %d\n", taskArray[i]->priority);
		free(taskArray[i]);
		taskArray[i] = NULL;
	printf("---------------------\n");

	}
}
void deleteTasks () {
	int arrayLength = sizeof(taskArray) / sizeof(taskArray[0]);
	int toDelete = 10;
	qsort(taskArray, taskNum, sizeof(taskArray[0]), comp);
	printf("Choose a task to delete:\n");	
	for (int i = 0; i < taskNum; i++) {
		if (taskArray[i] == NULL) continue;
		printf("---------------------\n");
		printf("Task number: %d\n", i);
		printf("Task name: %s\n", taskArray[i]->name);
		printf("Task priority: %d\n", taskArray[i]->priority);
	}
	printf("---------------------\n");
	--taskNum;
								
	while (!((toDelete >= 0) || (toDelete <= 9))) scanf("%d", &toDelete);

	for (int i = 0; i < arrayLength; i++) {
		if (taskArray[i] == NULL) continue;
		if (i == toDelete) {
			free(taskArray[i]);
			taskArray[i] = NULL;
			break;
		}
	}

	FILE* fptr = fileUse(WRITE);
	
	qsort(taskArray, arrayLength, sizeof(taskArray[0]), comp);
	for (int i = 0; i < taskNum; i++) {
		if (taskArray[i] == NULL) continue;
		fprintf(fptr, "%s", taskArray[i]->name);
		fprintf(fptr, "%d", taskArray[i]->priority);
		free(taskArray[i]);
		taskArray[i] = NULL;
	}

	fclose(fptr);
}

