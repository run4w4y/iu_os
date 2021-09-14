#include <stdio.h>
#include <unistd.h>

int n;

void child() {
    printf("Hello from child %d\n", getpid() - n);
}

void parent() {
    printf("Hello from parent %d\n", getpid() - n);
}

int main() {
    int f = fork();
    if (f == 0)
        child();
    else
        parent();
}