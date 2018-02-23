#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv) {
    printf("size of bool: %zu\n", sizeof(bool));
    printf("bool true:  0x%02x\n", (unsigned char)true);
    printf("bool false: 0x%02x\n", (unsigned char)false);

    /*
     * A true bool is any non-zero value, while false is a zero value.
     * Turning on compiler optimization on GCC-5 somehow breaks this code (it
     * prints false). Seems to work in GCC-7 however.
     */

    bool b = true;
    *(char*)&b = 2;

    if(b) {
        printf("2 is true\n");
    } else {
        printf("2 is false\n");
    }

    return 0;
}
