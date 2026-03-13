/* Ex04_reverse_number.c */
#include <stdio.h>

int reverse_rec(int n, int acc) {
    if (n == 0) return acc;
    return reverse_rec(n / 10, acc * 10 + (n % 10));
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n == 0) { printf("0\n"); return 0; }
    int rev = reverse_rec(n, 0);
    printf("%d\n", rev);
    return 0;
}
