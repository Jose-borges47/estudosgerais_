/* Ex01_print_naturals.c */
#include <stdio.h>

void print_from(int i, int n) {
    if (i > n) return;
    printf("%d", i);
    if (i < n) printf(" ");
    print_from(i+1, n);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("\n"); return 0; }
    print_from(1, n);
    printf("\n");
    return 0;
}
