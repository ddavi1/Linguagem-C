#include <stdio.h>

int main() {

    char sexo;
    int idade, peso;
    float altura;

    printf("Digite seu sexo: (m, M ou f, F): \n");
    scanf("%c", &sexo);

    printf("Digite sua idade: \n");
    scanf("%i", &idade);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu peso: \n");
    scanf("%i", &peso);

    printf("sexo: %c\nidade: %i\naltura: %.2f\npeso %ikg\n", sexo, idade, altura, peso);

    return 0;
}