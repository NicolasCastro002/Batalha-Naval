#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5
#define TENTATIVAS 5

// Função para inicializar o tabuleiro com '~'
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

// Função para exibir o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    int navioLinha, navioColuna;
    int linha, coluna;
    int tentativas = TENTATIVAS;
    int acertou = 0;

    srand(time(NULL)); // Seed para números aleatórios

    inicializarTabuleiro(tabuleiro);

    // Posiciona o navio aleatoriamente
    navioLinha = rand() % TAMANHO;
    navioColuna = rand() % TAMANHO;

    printf("=== BATALHA NAVAL (C) ===\n");
    printf("Você tem %d tentativas para acertar o navio escondido.\n\n", TENTATIVAS);

    while (tentativas > 0) {
        mostrarTabuleiro(tabuleiro);

        printf("Digite a linha (0 a %d): ", TAMANHO - 1);
        scanf("%d", &linha);
        printf("Digite a coluna (0 a %d): ", TAMANHO - 1);
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("⛔ Coordenadas inválidas. Tente novamente.\n\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != '~') {
            printf("⚠️ Você já tentou essa posição. Escolha outra.\n\n");
            continue;
        }

        if (linha == navioLinha && coluna == navioColuna) {
            printf("🎯 BOOM! Você acertou o navio!\n\n");
            tabuleiro[linha][coluna] = 'X';
            acertou = 1;
            break;
        } else {
            printf("💦 Água!\n\n");
            tabuleiro[linha][coluna] = 'O';
            tentativas--;
            printf("Tentativas restantes: %d\n\n", tentativas);
        }
    }

    if (!acertou) {
        printf("💥 Você perdeu! O navio estava em (%d, %d).\n", navioLinha, navioColuna);
        tabuleiro[navioLinha][navioColuna] = 'N';
    }

    printf("\nTabuleiro final:\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
