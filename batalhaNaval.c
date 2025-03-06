#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"

#define SIZE 10
#define NUM_NAVIOS 3
#define TAM_NAVIO 3

void inicializarCampo(int campo[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            campo[i][j] = 0;  // Inicializa tudo com água (0)
        }
    }
}

void imprimirCampo(int campo[SIZE][SIZE]) {
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) {
        printf(ANSI_COLOR_BLUE "%c " ANSI_COLOR_RESET, 'A' + i); // Índices das colunas em letras azuis
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf(ANSI_COLOR_YELLOW "%d " ANSI_COLOR_RESET, i); // Índices das linhas em números amarelos
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavios(int campo[SIZE][SIZE], int posicoes[NUM_NAVIOS][3][2]) {
    srand(time(NULL));

    for (int n = 0; n < NUM_NAVIOS; n++) {
        int x, y, orientacao, valido;

        do {
            valido = 1;
            x = rand() % SIZE;
            y = rand() % SIZE;
            orientacao = rand() % 2; // 0 = horizontal, 1 = vertical

            if ((orientacao == 0 && y + TAM_NAVIO > SIZE) || (orientacao == 1 && x + TAM_NAVIO > SIZE)) {
                valido = 0;
                continue;
            }

            for (int i = 0; i < TAM_NAVIO; i++) {
                if (orientacao == 0 && campo[x][y + i] != 0) {
                    valido = 0;
                    break;
                } else if (orientacao == 1 && campo[x + i][y] != 0) {
                    valido = 0;
                    break;
                }
            }
        } while (!valido);

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (orientacao == 0) {
                campo[x][y + i] = 1;
                posicoes[n][i][0] = x;
                posicoes[n][i][1] = y + i;
            } else {
                campo[x + i][y] = 1;
                posicoes[n][i][0] = x + i;
                posicoes[n][i][1] = y;
            }
        }
    }
}

int main() {
    //inicia um array com o tamanho do campo de batalha usando a variavel SIZE = 10
    int campo_batalha[SIZE][SIZE];
    int posicoes[NUM_NAVIOS][3][2];

    printf("Batalha Naval\n\n");
    printf("Seja bem-vindo ao jogo!\n");

    inicializarCampo(campo_batalha);
    posicionarNavios(campo_batalha, posicoes);
    imprimirCampo(campo_batalha);

    printf("\n\nNavios:\n");
    for (int n = 0; n < NUM_NAVIOS; n++) {
        printf("%dº navio nas posições: ", n + 1);
        for (int i = 0; i < TAM_NAVIO; i++) {
            printf("(%c, %d) ", 'A' + posicoes[n][i][1], posicoes[n][i][0]);
        }
        printf("\n");
    }

    return 0;
}