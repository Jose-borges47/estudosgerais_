/* Ex03_ackermann.c */
#include <stdio.h>
#include <limits.h>

unsigned long long ack(unsigned int m, unsigned int n) {
    if (m == 0) return (unsigned long long)(n + 1);
    if (n == 0) return ack(m - 1, 1);
    unsigned long long inner = ack(m, n - 1);
    return ack(m - 1, (unsigned int)inner);
}

int main(void) {
    unsigned int m, n;
    if (scanf("%u %u", &m, &n) != 2) return 0;
    unsigned long long res = ack(m, n);
    printf("%llu\n", res);
    return 0;
}
