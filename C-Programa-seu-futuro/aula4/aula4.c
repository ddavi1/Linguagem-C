#include <stdio.h>

int main () {

    int valor, valor2; // criei uma variavel para guardar um valor do tipo inteiro

    printf("digite um numero: ");
    scanf("%i", &valor);

     printf("digite um segundo numero: ");
     scanf("%i", &valor2);

    printf("\n\nPrimeiro: %i\nSegundo valor: %i", valor, valor2);
    

    return 0;
}