#include <stdio.h>
#include <string.h>
int login(char user[], char pass[]) {
    char valid_user[] = "admin";
    char valid_pass[] = "1234";
    if (strcmp(user, valid_user) == 0 && strcmp(pass, valid_pass) == 0)
        return 1;
    return 0;
}
int main() {
    char user[50], pass[50];
    printf("Usuario: ");
    scanf("%s", user);
    printf("Senha: ");
    scanf("%s", pass);
    if (login(user, pass))
        printf("Acesso concedido\n");
    else
        printf("Acesso negado\n");
    return 0;
}