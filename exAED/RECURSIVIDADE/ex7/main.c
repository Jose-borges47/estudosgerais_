/* Ex07_banco_inteligente.c */
#include <stdio.h>

int valores[6] = {2, 5, 10, 20, 50, 100};
int notas[6];
int S;

int contar_maneiras(int i, int restante) {
    if (restante == 0) return 1;
    if (i == 6 || restante < 0) return 0;

    int total = 0;
    for (int q = 0; q <= notas[i] && q * valores[i] <= restante; q++)
        total += contar_maneiras(i + 1, restante - q * valores[i]);
    return total;
}

int main(void) {
    scanf("%d", &S);
    for (int i = 0; i < 6; i++) scanf("%d", &notas[i]);
    printf("%d\n", contar_maneiras(0, S));
    return 0;
}
