/* Ex11_batalha_naval.c */
#include <stdio.h>

#define MAX 100

char tab[MAX][MAX];
int visit[MAX][MAX];
int n, m;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dentro(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

void dfs_navio(int i, int j, int *partes, int *acertos) {
    visit[i][j] = 1;
    (*partes)++;
    if (tab[i][j] == 'X') (*acertos)++;
    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (dentro(ni, nj) && !visit[ni][nj] && (tab[ni][nj] == '#' || tab[ni][nj] == 'X'))
            dfs_navio(ni, nj, partes, acertos);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &tab[i][j]);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        L--; C--;
        if (tab[L][C] == '#') tab[L][C] = 'X';
    }

    int destruidos = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visit[i][j] && (tab[i][j] == '#' || tab[i][j] == 'X')) {
                int partes = 0, acertos = 0;
                dfs_navio(i, j, &partes, &acertos);
                if (partes == acertos) destruidos++;
            }

    printf("%d\n", destruidos);
    return 0;
}
