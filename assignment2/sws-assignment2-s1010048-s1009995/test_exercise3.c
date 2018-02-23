#include <stdio.h>

void addvector(int *r, const int *a, const int *b, unsigned int len);
int memcmp(const void *s1, const void *s2, size_t n);
int memcmp_backwards(const void *s1, const void *s2, size_t n);
int memcmp_fast(const void *s1, const void *s2, size_t n);
int memcmp_consttime(const void *s1, const void *s2, size_t n);

int main(int argc, char** argv) {
    unsigned int len = 4;
    int r[len];
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int c[] = {5, 8, 7, 9};
    char l1[] = "This is a long test message for memcp_fast";
    char l2[] = "This is a long test message for Memcp_fast";

    addvector(&r[0], &a[0], &b[0], len);

    printf("r=");
    for(size_t i = 0; i < len; ++i) {
        printf("%d ", r[i]);
    }

    printf("\nmemcmp: %d\n", memcmp(&b, &c, len * sizeof(int)));
    printf("memcmp_backwards: %d\n", memcmp_backwards(&b, &c, len * sizeof(int)));
    printf("memcmp_fast: %d\n", memcmp_fast(&l1, &l2, sizeof(l1)));
    printf("memcmp_consttime: %d\n", memcmp_consttime(&b, &c, len * sizeof(int)));

    return 0;
}
