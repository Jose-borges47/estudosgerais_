/* Ex08_familias_troia.c */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 50000
#define MAXM 100000

int n, m;
int *adj[MAXN + 1];
int grau[MAXN + 1];
int vis[MAXN + 1];

void dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < grau[v]; i++) {
        int u = adj[v][i];
        if (!vis[u]) dfs(u);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) grau[i] = 0, adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        grau[a]++; grau[b]++;
        adj[a] = realloc(adj[a], grau[a] * sizeof(int));
        adj[b] = realloc(adj[b], grau[b] * sizeof(int));
        adj[a][grau[a] - 1] = b;
        adj[b][grau[b] - 1] = a;
    }

    int familias = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) { dfs(i); familias++; }

    printf("%d\n", familias);
    return 0;
}
