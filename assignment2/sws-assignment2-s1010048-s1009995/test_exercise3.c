#include <stdio.h>

void addvector(int *r, const int *a, const int *b, size_t len);
int my_memcmp(const void *s1, const void *s2, size_t n);
int my_memcmp_backwards(const void *s1, const void *s2, size_t n);

int main(int argc, char** argv) {
    size_t len = 4;
    int r[len];
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int c[] = {5, 8, 7, 9};

    addvector(&r[0], &a[0], &b[0], len);

    for(size_t i = 0; i < len; ++i) {
        printf("%d\n", r[i]);
    }


    int res = my_memcmp(&b, &c, len * sizeof(int));

    printf("%d\n", res);
    printf("%d\n", my_memcmp_backwards(&b, &c, len * sizeof(int)));

    return 0;
}
