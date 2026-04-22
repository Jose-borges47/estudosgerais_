#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "avl.h"

void carregarDeArquivo(ArvAVL *raiz, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");

    if (!f) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    char palavra[100];

    while (fgets(palavra, sizeof(palavra), f)) {
        palavra[strcspn(palavra, "\n")] = '\0'; // remove \n
        insere_ArvAVL(raiz, palavra);
    }

    fclose(f);
}