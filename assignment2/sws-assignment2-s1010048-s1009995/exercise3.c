#include <stdio.h>

void addvector(int *r, const int *a, const int *b, size_t len) {
    for(size_t i = 0; i < len; ++i, ++r, ++a, ++b) {
        *r = *a + *b;
    }
}

int my_memcmp(const void *s1, const void *s2, size_t n) {
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;

    for(size_t i = 0; i < n; ++i, ++p1, ++p2) {
        if(*p1 != *p2) {
            return *p1 - *p2;
        }
    }

    return 0;
}

int my_memcmp_backwards(const void *s1, const void *s2, size_t n) {
    char* p1 = ((char*)s1) + n - 1;
    char* p2 = ((char*)s2) + n - 1;

    for(size_t i = 0; i < n; ++i, --p1, --p2) {
        if(*p1 != *p2) {
            return *p1 - *p2;
        }
    }

    return 0;
}
