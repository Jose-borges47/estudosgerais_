/* Ex05_dec_to_bin.c */
#include <stdio.h>

void print_bin(unsigned int n) {
    if (n < 2) {
        printf("%u", n);
        return;
    }
    print_bin(n / 2);
    printf("%u", n % 2);
}

int main(void) {
    int k;
    if (scanf("%d", &k) != 1) return 0;
    while (k--) {
        unsigned int n;
        if (scanf("%u", &n) != 1) return 0;
        if (n == 0) printf("0\n");
        else {
            print_bin(n);
            printf("\n");
        }
    }
    return 0;
}
