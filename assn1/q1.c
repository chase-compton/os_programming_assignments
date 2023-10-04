#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;

    printf("Initial value of x: %d\n", x);

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        x += 50;
        printf("Child process - Value of x: %d\n", x);
    } else {
        // Parent process
        x -= 30;
        printf("Parent process - Value of x: %d\n", x);
    }

    return 0;
}
