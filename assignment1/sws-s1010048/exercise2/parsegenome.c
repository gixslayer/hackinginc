#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("usage: %s file\n", argv[0]);
        return 0;
    }

    bool valid = true;
    int lines = 0;
    int line_length = 0;
    int n_a = 0;
    int n_c = 0;
    int n_g = 0;
    int n_t = 0;
    int c;

    FILE* file = fopen(argv[1], "r");
    if(!file) {
        printf("Could not open file: %s (%d)\n", strerror(errno), errno);
        return 0;
    }

    do {
        c = fgetc(file);
        ++line_length;

        switch(c) {
            case '\n':
                valid = line_length == 101; // 100 + 1 for the newline character
                ++lines; 
                line_length = 0; 
                break;
            case 'A': ++n_a; break;
            case 'C': ++n_c; break;
            case 'G': ++n_g; break;
            case 'T': ++n_t; break;
            default: valid &= c == EOF; break;
        }
    } while(c != EOF && valid);

    valid &= lines == 500;
    fclose(file);

    if(valid) {
        printf("a=%d, c=%d, g=%d, t=%d\n", n_a, n_c, n_g, n_t);
    }

    return valid ? 0 : -1;
}