/* Ex10_setas.c */
#include <stdio.h>

#define MAX 500

char tab[MAX][MAX];
int estado[MAX][MAX]; // 0=não visitado,1=em visita,2=seguro,3=fora
int n;

int dentro(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

int dfs(int i, int j) {
    if (!dentro(i, j)) return 0;
    if (estado[i][j] == 1) return 1; // ciclo (seguro)
    if (estado[i][j] == 2) return 1;
    if (estado[i][j] == 3) return 0;

    estado[i][j] = 1;
    int ni = i, nj = j;
    switch (tab[i][j]) {
        case 'A': ni = i - 1; break;
        case 'V': ni = i + 1; break;
        case '<': nj = j - 1; break;
        case '>': nj = j + 1; break;
    }
    int seguro = dfs(ni, nj);
    estado[i][j] = seguro ? 2 : 3;
    return seguro;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &tab[i][j]);

    int cont = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dfs(i, j)) cont++;

    printf("%d\n", cont);
    return 0;
}
