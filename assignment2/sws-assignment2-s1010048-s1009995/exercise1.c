#include <stdio.h>

void print_var(void* var, size_t size, const char* name) {
    unsigned char* ptr = var;

    for(size_t i = 0; i < size; ++i, ++ptr) {
        printf("%p | 0x%02x          | %3d           | %s\n", ptr, *ptr, *ptr, i == 0 ? name : "");
    }
}

int main(int argc, char** argv) {
    short i = 0x1234;
    char x = -127;
    long sn1 = 1010048;
    long sn2 = 1009995;
    int y[2] = {0x11223344, 0x44332211};

    printf("size of x:   %zu\n", sizeof(x));
    printf("size of i:   %zu\n", sizeof(i));
    printf("size of sn1: %zu\n", sizeof(sn1));
    printf("size of sn2: %zu\n", sizeof(sn2));
    printf("size of y:   %zu\n\n", sizeof(y));

    printf("address        | content (hex) | content (dec) | variable\n");
    printf("---------------|---------------|---------------|---------\n");
    print_var(&i, sizeof(i), "i");
    print_var(&x, sizeof(x), "x");
    print_var(&sn1, sizeof(sn1), "sn1");
    print_var(&sn2, sizeof(sn2), "sn2");
    print_var(&y, sizeof(y), "y");

    return 0;
}

