#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    pid_t p1 = fork();

    if(p1 == 0) {
        execlp("python", "python", "add.py", argv[1], argv[2], NULL);
        exit(0);
    }
    pid_t p2 = fork();
    if(p2 == 0) {
         execlp("java", "java", "subtraction.java", argv[1], argv[2], NULL);
        exit(0);
    }
    pid_t p3 = fork();
    if(p3 == 0) {
         execlp("node", "node", "multiplication.js", argv[1], argv[2], NULL);
        exit(0);
    }

    pid_t p4 = fork();
    if(p4 == 0) {
         execlp("bash", "bash", "division.sh", argv[1], argv[2], NULL);
        exit(0);
    }
    wait(NULL);
    wait(NULL);   
    wait(NULL);   
    wait(NULL);   
    printf("%s\n","parent done.");
    return 0; 
}
