#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int* f, int* s, int n) {
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n-i-1; ++j) 
            if (f[j] > f[j+1]) {
                swap(&f[j], &f[j+1]);
                swap(&s[j], &s[j+1]);
            }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* arrival = (int*) malloc(sizeof(int) * n);
    int* burst = (int*) malloc(sizeof(int) * n);
    int* completion = (int*) malloc(sizeof(int) * n);
    int* remaining_burst = (int*) malloc(sizeof(int) * n);
    int wait_total = 0;
    int turn_total = 0;
    

    for (int i = 0; i < n; ++i) 
        scanf("%d %d", arrival + i, burst + i);

    sort(arrival, burst, n);
    
    for (int i = 0; i < n; ++i)
        remaining_burst[i] = burst[i];

    int t = arrival[0];

    bool f = 0;
    do {

        for (int i = 0; i < n; ++i) {
            if (t >= arrival[i] && remaining_burst[i] > 0) {
                f = 1;
                remaining_burst[i] -= q;
                t += q;

                if (remaining_burst[i] <= 0 {
                    completion[i] = t;
                    turn = completion[i] - arrival[i];
                    wait = turn[i] - burst[i];
                    turn_total += turn;
                    wait_total += wait;

                    printf("Process #%d results:\n\tTurnaround time: %d\n\tWaiting time: %d\n\tCompletion time: %d\n", i, turn, wait, completion);
                }
            }
        }
    } while (f);

    printf("Average turnaround: %f\n", (double)turn_total / n);
    printf("Average waiting: %f\n", (double)wait_total / n);
    
    return 0;
}