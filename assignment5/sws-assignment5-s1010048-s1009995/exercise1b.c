#include <stdio.h>

void function_b(void) {
    char buffer[4];

    // Move the saved frame pointer into the current frame pointer.
    // Once this function returns, it will actually return as function_a, thus skip the 'Executed' print.
    __asm__("movq (%rbp), %rbp");

    fprintf(stdout, "Executing function_b\n");
}

void function_a(void) {
    int beacon = 0xa0b1c2d3;
    fprintf(stdout, "Executing function_a\n");
    function_b();
    fprintf(stdout, "Executed function_b\n");
}

int main(void) {
    function_a();
    fprintf(stdout, "Finished!\n");
    return 0;
}
