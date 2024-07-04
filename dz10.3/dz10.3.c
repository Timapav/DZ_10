#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_ARGS 10

int main() {
    char command[MAX_INPUT];
    char *args[MAX_ARGS];
    pid_t pid;

    while (1) {
        printf("Введите имя программы и опции запуска: ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Ошибка чтения команды");
            continue;
        }
        command[strcspn(command, "\n")] = 0; 

       
        if (strcmp(command, "exit") == 0) {
            break;
        }

        int i = 0;
        args[i] = strtok(command, " ");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid = fork();
        if (pid == 0) {
           
            execvp(args[0], args);
            perror("Ошибка выполнения команды");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            
            wait(NULL);
        } else {
            perror("Ошибка создания процесса");
        }
    }

    return 0;
}
