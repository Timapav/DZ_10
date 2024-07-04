#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        
        printf("Child process: pid = %d, ppid = %d\n", getpid(), getppid());
        
        exit(0);
    } else {
        
        wait(NULL);

        printf("Main process: pid = %d, ppid = %d\n", getpid(), getppid());

        int status;
        wait(&status);

        printf("Child procex completion status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
