/* Ex09_torre_hanoi.c */
#include <stdio.h>

void mover(int n, char origem, char destino, char aux) {
    if (n == 1) {
        printf("(%c,%c)\n", origem, destino);
        return;
    }
    mover(n - 1, origem, aux, destino);
    printf("(%c,%c)\n", origem, destino);
    mover(n - 1, aux, destino, origem);
}

int main(void) {
    int n;
    scanf("%d", &n);
    mover(n, 'O', 'D', 'A');
    return 0;
}
