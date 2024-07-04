#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    pid_t pid1, pid2, pid3, pid4, pid5;


    pid1 = fork();
    if (pid1 == 0) {

        pid3 = fork();
        if (pid3 == 0) {

            printf("Process3: pid = %d, ppid = %d\n", getpid(), getppid());

            exit(0);
        } else {

            wait(NULL);

            printf("Process1: pid = %d, ppid = %d\n", getpid(), getppid());

            exit(0);
        }
    } else {

        pid4 = fork();
        if (pid4 == 0) {

            printf("Process4: pid = %d, ppid = %d\n", getpid(), getppid());

            exit(0);
        } else {

            wait(NULL);

            pid2 = fork();
            if (pid2 == 0) {

                pid5 = fork();
                if (pid5 == 0) {

                    printf("Process5: pid = %d, ppid = %d\n", getpid(), getppid());

                    exit(0);
                } else {

                    wait(NULL);

                    printf("Process2: pid = %d, ppid = %d\n", getpid(), getppid());

                    exit(0);
                }
            } else {

                wait(NULL);

                wait(NULL);

                printf("Main process: pid = %d, ppid = %d\n", getpid(), getppid());

                exit(0);
            }
        }
    }

    return 0;
}
