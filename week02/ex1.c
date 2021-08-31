#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("size of variable int a %lu\n", sizeof a);
    printf("size of variable float b %lu\n", sizeof b);
    printf("size of variable double c %lu\n", sizeof c);
    printf("value of variable int a %d\n", a);
    printf("value of variable float b %lf\n", b);
    printf("value of variable double c %lf", c);

    return 0;
}