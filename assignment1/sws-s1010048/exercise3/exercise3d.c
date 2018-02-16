#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    FILE* file = fopen("/dev/urandom", "r");
    uint16_t c;

    do {
        c = fgetc(file);
        c |= fgetc(file) << 8;

        printf("%04x\n", c);
    } while(c != 42);

    return 0;
}