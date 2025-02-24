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

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
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
        printf(ANSI_COLOR_BLUE "%d ", i); // Imprime o índice das colunas
        //printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");

    }
    printf("\n"  ANSI_COLOR_RESET);

    for (int i = 0; i < SIZE; i++) {
        printf(ANSI_COLOR_YELLOW "%d " ANSI_COLOR_RESET, i); // Imprime o índice das linhas
        for (int j = 0; j < SIZE; j++) {
            printf( "%d ", campo[i][j]);
        }
    printf("\n"  ANSI_COLOR_RESET);
    }
}

void posicionarNavios(int campo[SIZE][SIZE]) {
    srand(time(NULL));

    for (int n = 0; n < NUM_NAVIOS; n++) {
        int x, y, orientacao, valido;

        do {
            valido = 1;
            x = rand() % SIZE;
            y = rand() % SIZE;
            orientacao = rand() % 2; // 0 = horizontal, 1 = vertical

            // Verifica se cabe na matriz
            if ((orientacao == 0 && y + TAM_NAVIO > SIZE) || (orientacao == 1 && x + TAM_NAVIO > SIZE)) {
                valido = 0;
                continue;
            }

            // Verifica se já existe um navio no espaço
            for (int i = 0; i < TAM_NAVIO; i++) {
                if (orientacao == 0 && campo[x][y + i] != 0) {
                    valido = 0;
                    break;
                } else if (orientacao == 1 && campo[x + i][y] != 0) {
                    valido = 0;
                    break;
                }
            }

        } while (!valido); // Repete até encontrar uma posição válida

        // Posiciona o navio
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (orientacao == 0) {
                campo[x][y + i] = 1; // Navio na horizontal
            } else {
                campo[x + i][y] = 1; // Navio na vertical
            }
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int campo_batalha[SIZE][SIZE];

    printf("Batalha Naval\n\n");
    printf("Seja bem-vindo ao jogo!\n");

    inicializarCampo(campo_batalha);
    posicionarNavios(campo_batalha);
    imprimirCampo(campo_batalha);

    printf("\nCom auxílio do tabuleiro acima, vamos começar o jogo!\n");
    printf("Digite a posição para atirar!\n");

    return 0;
}
