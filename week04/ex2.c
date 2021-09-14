#include <unistd.h>

int main() {
    for (int i = 0; i < 3; ++i) {
        int f = fork();
    }
    sleep(5);
}