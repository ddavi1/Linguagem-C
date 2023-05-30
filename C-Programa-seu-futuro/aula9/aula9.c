#include <stdio.h>

int main () {

    char letra;

    printf("Digite um caracter: ");
    letra = fgetc(stdin);

    printf("caracter lido: %c", letra);

    return 0;
}