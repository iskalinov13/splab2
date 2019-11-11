#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_LINE 80
int main() 
{ 
	char user_input[MAX_LINE]; 
	int i = 0;
	int waite = 0;

	while (1) {

		printf("$ Enter your command: ");
		fgets(user_input, MAX_LINE, stdin);

		waite = 0;
		i = 0;
		char *args[MAX_LINE];
		args[i] = strtok(user_input, " \n");

		if (strcmp(user_input, "exit") == 0) {
			break;
		}

		while (args[i] != NULL) {
			if (strcmp(args[i], "&")) {
				i++;
				args[i] = strtok(NULL, " \n");	
			} else {
				waite = 1;
				args[i] = NULL;
			}
		}

		pid_t pid; 
		pid = fork(); 
		
		if(pid < 0){ 
			printf("ERROR: Fork error");
		}
		if (pid == 0){
			execvp(args[0],args); 
			
			if (execvp(args[0],args) < 0) {     
				printf("ERROR: Invalid command\n");
				break;
			}
		}
		if (waite==1)
			wait(0);
			wait(0);
			wait(0);
			wait(0);
		}
  
    return 0; 
} 
