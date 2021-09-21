#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 5

int data[N];
int counter = 0;

void* producer_f(void* arg) {
    while (1) {
        while (counter >= N) {}

        if (counter >= N)
            printf("race condition occured");

        data[counter] = rand();
        ++counter;
    }
}

void* consumer_f(void* arg) {
    while (1) {
        while (counter <= 0) {}

        if (counter <= 0) 
            printf("race condition occured");

        data[counter] = rand();
        --counter;
    }
}

int main() {
    pthread_t t_producer, t_consumer;
    pthread_create(&t_producer, NULL, producer_f, NULL);
    pthread_create(&t_consumer, NULL, consumer_f, NULL);

    pthread_join(t_consumer, NULL);
    pthread_join(t_producer, NULL);

    return 0;
}
