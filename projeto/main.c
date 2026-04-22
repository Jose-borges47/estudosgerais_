// Integrantes: José borges da Cruz - 202403078

#include <stdio.h>
#include <string.h>
#include "avl.h"
#include "utils.h"

int main() {
    ArvAVL *raiz = cria_ArvAVL();
    char entrada[100];

    // 🔹 Carrega palavras iniciais (opcional)
    carregarDeArquivo(raiz, "br-sem-acentos.txt");

    printf("=== Dicionario com Autocomplete ===\n");

    while (1) {
        printf("\nDigite um prefixo (ou 'sair'): ");

        if (scanf("%s", entrada) == EOF)
            break;

        if (strcmp(entrada, "sair") == 0)
            break;

        autocomplete(raiz, entrada);
    }

    libera_ArvAVL(raiz);

    printf("\nPrograma encerrado.\n");

    return 0;
}