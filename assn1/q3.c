#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("Child process executing...\n");
        sleep(3);  // fake work
        printf("Child process finished.\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        int status_wait, status_waitpid;

        // printf("Parent waiting for child to finish using wait()...\n");
        // pid_t waited_pid = wait(&status_wait);
        // printf("Parent: Child process with PID %d finished with status %d.\n", waited_pid, status_wait);

        printf("\nParent waiting for child to finish using waitpid()...\n");
        pid_t waited_pid_pid = waitpid(pid, &status_waitpid, 0);
        printf("Parent: Child process with PID %d finished with status %d.\n", waited_pid_pid, status_waitpid);
    }

    return 0;
}
