/* Ex02_fibonacci_bigrec.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char *memo[MAXN+1];

char *str_add(const char *a, const char *b) {
    int la = strlen(a), lb = strlen(b);
    int L = (la > lb ? la : lb) + 1;
    char *res = malloc(L + 1);
    int carry = 0, ia = la - 1, ib = lb - 1, ir = L - 1;
    res[L] = '\0';
    while (ir >= 0) {
        int da = (ia >= 0 ? a[ia] - '0' : 0);
        int db = (ib >= 0 ? b[ib] - '0' : 0);
        int s = da + db + carry;
        res[ir] = '0' + (s % 10);
        carry = s / 10;
        ia--; ib--; ir--;
    }
    // remove leading zero if any
    if (res[0] == '0') {
        char *t = strdup(res + 1);
        free(res);
        return t;
    }
    return res;
}

char *fib_str(int n) {
    if (memo[n]) return memo[n];
    if (n == 0) { memo[n] = strdup("0"); return memo[n]; }
    if (n == 1) { memo[n] = strdup("1"); return memo[n]; }
    char *a = fib_str(n-1);
    char *b = fib_str(n-2);
    char *s = str_add(a, b);
    memo[n] = s;
    return memo[n];
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) return 0;
    for (int i = 0; i <= n; ++i) {
        char *s = fib_str(i);
        printf("%s", s);
        if (i < n) printf(" ");
    }
    printf("\n");
    // liberar memória (opcional em programa curto)
    for (int i = 0; i <= n; ++i) if (memo[i]) free(memo[i]);
    return 0;
}
