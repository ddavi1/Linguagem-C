#include <stdio.h>

int main() {

    char sexo; // para atribuir valores para char voce usa aspas simples

    printf("digite seu sexo: (f, F, m ou M):\n"); // %c = char
    scanf("%c", &sexo);

    printf("valor da variavel sexo : %c", sexo);


}