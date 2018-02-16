#include <stdio.h>

int main(int argc, char** argv) {
    FILE* file = fopen("/dev/urandom", "r");
    int c;

    do {
        c = fgetc(file);

        printf("%d %u %x\n", c, c, c);
    } while(c != 42);

    return 0;
}