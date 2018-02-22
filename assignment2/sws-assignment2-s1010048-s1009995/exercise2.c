#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv) {
    printf("size of bool: %zu\n", sizeof(bool));
    printf("bool true:  0x%02x\n", (unsigned char)true);
    printf("bool false: 0x%02x\n", (unsigned char)false);

    bool b = true;
    *(char*)&b = 2;

    if(b) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
