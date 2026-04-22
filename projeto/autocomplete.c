#include <avl.c>

void autocompleteAux(ArvAVL *raiz, char prefixo[], int *found) {
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        autocompleteAux(&((*raiz)->esq), prefixo, found);

        if (strncmp((*raiz)->info, prefixo, strlen(prefixo)) == 0){
            printf("%s\n\n", (*raiz)->info);
            *found = 1;
        }

        autocompleteAux(&((*raiz)->dir), prefixo, found);
    }
}

void autocomplete(ArvAVL *raiz, char prefixo[]) {
    if(raiz == NULL || *raiz == NULL){
        printf("Arvore vazia\n");
        return;
    }

    int found = 0;

    printf("\nSugestoes para \"%s\":\n", prefixo);

    autocompleteAux(raiz, prefixo, &found);

    if (!found) {
        printf("Nenhuma sugestao encontrada\n");
    }
}