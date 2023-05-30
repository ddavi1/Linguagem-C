#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 30
#define HEIGHT 20

int tardisX, tardisY; // Posi��o da TARDIS
int blockX, blockY; // Posi��o do bloco
int score; // Pontua��o do jogador

void setup() {
    // Inicializar as posi��es iniciais
    tardisX = WIDTH / 2;
    tardisY = HEIGHT - 1;
    blockX = 0;
    blockY = HEIGHT / 2;
    score = 0;
}

void draw() {
    system("cls"); // Limpar a tela

    // Desenhar a grade do jogo
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == tardisY && j == tardisX) {
                printf("T"); // Desenhar a TARDIS
            } else if (i == blockY && j == blockX) {
                printf("B"); // Desenhar o bloco
            } else {
                printf(" "); // Espa�o vazio
            }
        }
        printf("\n");
    }

    // Mostrar a pontua��o
    printf("Score: %d\n", score);
}

void input() {
    // Verificar se alguma tecla foi pressionada
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                tardisX--; // Mover para a esquerda
                break;
            case 'd':
                tardisX++; // Mover para a direita
                break;
            case 'q':
                exit(0); // Sair do jogo
                break;
        }
    }
}

void update() {
    // Atualizar a posi��o do bloco
    blockX++;

    // Verificar se a TARDIS colidiu com o bloco
    if (tardisX == blockX && tardisY == blockY) {
        score++; // Incrementar a pontua��o
        blockX = 0; // Reiniciar a posi��o do bloco
    }

    // Verificar se o bloco ultrapassou a borda direita
    if (blockX >= WIDTH) {
        blockX = 0; // Reiniciar a posi��o do bloco
    }
}

int main() {
    setup();

    while (1) {
        draw();
        input();
        update();
        Sleep(100); // Aguardar um tempo para atualizar o jogo (100 ms)
    }

    return 0;
}
