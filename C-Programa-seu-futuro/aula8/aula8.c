#include <stdio.h>

int main () {


    char letra;

    printf("Digite um caracter: ");
    letra = getc(stdin); // stdin = direto do teclado

    printf("caracter lido : %c", letra);

    return 0;
}