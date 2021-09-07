#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) 
                swap(&a[j], &a[j + 1]);
        }
    }
}

int main() {
    int a[] = {3, 6, 2, 1, 4, 5};
    int n = sizeof(a) / sizeof(int);
    bubble_sort(a, n);
    for (int i = 0; i < 6; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
