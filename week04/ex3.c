#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main() {
    while (true) {
        printf("$ ");
        char buf[256] = "";
        scanf("%s", buf);

        int p[2];
        if (pipe(p) == -1)
            exit(1);

        int f = fork();
    
        if (f == 0) {
            char* b[256+5] = "";
            strcat(b, "/bin/");
            strcat(b, buf);
            char* argv[2] = {b};

            close(p[0]);
            dup2(p[1], 1);
            dup2(p[1], 2);
            close(p[1]);
            execve(b, argv, NULL);

            return 0;
        } else {
            wait(NULL);
            close(p[1]);

            char out[1024] = "";
            while (read(p[0], out, sizeof(out)) != 0) {
                printf(out);
            }

            close(p[0]);
        }
    }
}