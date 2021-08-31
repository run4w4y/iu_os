#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    size_t height;
    scanf("%ld", &height);
    size_t space = height;

    for (size_t i = 1; i < height * 2; i += 2, --space) {
        char *tmp = NULL;
        tmp = malloc(i + 1);
        memset(tmp, '*', i);
        printf("%*s%s\n", space, " ", tmp);
        free(tmp);
    }

    return 0;
}
