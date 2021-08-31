#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str) {
    char *start, *end, tmp;
    size_t len = strlen(str);

    start = str;
    end = start + len - 1;

    while (start < end) {
        tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

int main() {
    char *buf = NULL;
    int read;
    size_t len;
    read = getline(&buf, &len, stdin);
    reverse_string(buf);
    printf("%s", buf);
    return 0;
}