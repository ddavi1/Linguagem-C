#include <stdio.h>

int main () {
    float numero = 3.1415;

    printf("%.4f\n", numero);

    printf("digite um numero real: ");
    scanf("%f", &numero);

    printf("numero digitado foi: %.3f", numero);

    //%i ou %d = inteiro
    // %f ou %d = float ou double
    // .4 ou . alguma coisa para pular casas decimais
}