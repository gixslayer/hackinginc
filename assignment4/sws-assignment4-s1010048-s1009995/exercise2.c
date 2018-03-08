#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define SN_1 "1010048"
#define SN_2 "1009995"
#define FREE_SN 0

void heap_attack(void) {
    char* s = malloc(8);
    char* s1 = NULL;
    char* s2 = NULL;

    // We only needed the address, so free the buffer.
    free(s);

    // Search for the start of the two strings.
    do {
        if(!strcmp(s, SN_1)) {
            printf("Found %s at %p\n", SN_1, s);
            s1 = s;
        } else if(!strcmp(s, SN_2)) {
            printf("Found %s at %p\n", SN_2, s);
            s2 = s;
        }

        --s;
    } while(s1 == NULL || s2 == NULL);

    // Replace all bytes between the two strings with spaces, thus removing null terminator from s1.
    memset(s1 + 7, ' ', s2 - s1 - 7);
}

int main(void) {
    char *s1 = malloc(8);
    if(s1 == NULL) return -1;
    char *s2 = malloc(8);
    if(s2 == NULL) return -1;

    strcpy(s1, SN_1);
    strcpy(s2, SN_2);

    heap_attack();

    printf("student 1: %s\n", s1);
    printf("student 2: %s\n", s2);

#if FREE_SN
    free(s1);
    free(s2);
#endif

    return 0;
}
