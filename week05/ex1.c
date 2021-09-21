#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* f(void* arg) {
    pthread_exit(0);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        char* ns = calloc(42 * sizeof(char), 0);
        sprintf(ns, "%d", i);
        pthread_t t;
        pthread_create(&t, NULL, f, &ns);
        printf("thread %d created\n", i);
        pthread_join(t, NULL);
    }

    return 0;
}
