#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arrival = (int*) malloc(sizeof(int) * n);
    int* burst = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) 
        scanf("%d %d", arrival + i, burst + i);

    int count = 0;
    int t = 0;
    int turn_total = 0;
    int wait_total = 0;

    while (count < n) {
        int min_val = INT_MAX;
        int min_idx = -1;

        for (int i = 0; i < n; ++i) {
            if (arrival[i] == -1 || arrival[i] > t)
                continue;
            
            if (burst[i] < min_val) {
                min_val = burst[i];
                min_idx = i;
            }
        }

        if (min_idx == -1) {
            printf("[%d] No processes to be executed\n", t);
            ++t;
            continue;
        }

        int wait = t - arrival[min_idx];
        printf("[%d] Executing process #%d\n", t, min_idx);
        t += burst[min_idx];
        printf("[%d] Process #%d was executed\n", t, min_idx);
        burst[min_idx] = arrival[min_idx] = -1;
        ++count;
        
        int turn = t - arrival[min_idx];
        printf("Process #%d results:\n\tTurnaround time: %d\n\tWaiting time: %d\n", min_idx, turn, wait);
        turn_total += turn;
        wait_total += wait;
    }

    printf("Completion time: %d\n", t);
    printf("Average turnaround: %f\n", (double)turn_total / n);
    printf("Average waiting: %f\n", (double)wait_total / n);

    return 0;
}