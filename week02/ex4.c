#include <stdio.h>

void swap_integers(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("a: %d, b: %d\n", a, b);
    swap_integers(&a, &b);
    printf("a: %d, b: %d", a, b);
    return 0;
}
