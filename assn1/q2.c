#include <sys/wait.h> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process

        // execl()
        // printf("Executing using execl()\n");
        // execl("/bin/ls", "ls", "-l", NULL);

        // execle()
        // printf("Executing using execle()\n");
        // char *envp[] = { "PATH=/usr/bin", NULL };
        // execle("/bin/ls", "ls", "-l", NULL, envp);

        // execlp()
        // printf("Executing using execlp()\n");
        // execlp("ls", "ls", "-l", NULL);

        // execv()
        // printf("Executing using execv()\n");
        // char *args[] = {"ls", "-l", NULL };
        // execv("/bin/ls", args);

        // execvp()
        printf("Executing using execvp()\n");
        char *args[] = {"ls", "-l", NULL };
        execvp("ls", args);

        //execvpe()
        // printf("Executing using execvpe()\n");
        // char *args[] = { "ls", "-l", NULL };
        // char *envp[] = { "PATH=/usr/bin", NULL };
        // execvpe("ls", args, envp);

        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}
