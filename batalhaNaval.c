#include <stdio.h>

#define TAB5 5
#define TAB10 10

// --- Nível Novato ---
void nivel_novato() {
    int tabuleiro[TAB5][TAB5] = {0};  // Inicializa tudo com 0

    // Posicionando navio horizontal tamanho 3 na linha 1, colunas 1 a 3
    for (int c = 1; c <= 3; c++) {
        tabuleiro[1][c] = 3;
        printf("Navio horizontal parte em: (%d, %d)\n", 1, c);
    }

    // Posicionando navio vertical tamanho 3 na coluna 4, linhas 2 a 4
    for (int l = 2; l <= 4; l++) {
        tabuleiro[l][4] = 3;
        printf("Navio vertical parte em: (%d, %d)\n", l, 4);
    }
}

// --- Nível Aventureiro ---
void nivel_aventureiro() {
    int tabuleiro[TAB10][TAB10] = {0};

    // Navio horizontal tamanho 3: linha 3, colunas 2 a 4
    for (int c = 2; c < 5; c++) tabuleiro[3][c] = 3;

    // Navio vertical tamanho 3: coluna 7, linhas 5 a 7
    for (int l = 5; l < 8; l++) tabuleiro[l][7] = 3;

    // Navio diagonal (descendente) tamanho 3: (0,0), (1,1), (2,2)
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = 3;

    // Navio diagonal (ascendente) tamanho 3: (9,2), (8,3), (7,4)
    for (int i = 0; i < 3; i++) tabuleiro[9 - i][2 + i] = 3;

    // Exibe tabuleiro
    printf("\nTabuleiro 10x10 com 4 navios:\n");
    for (int l = 0; l < TAB10; l++) {
        for (int c = 0; c < TAB10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

// --- Nível Mestre ---
// Habilidades especiais: cone, cruz, octaedro em matriz 5x5
void nivel_mestre() {
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Preenche cone (padrão 3 linhas centralizadas)
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    for (int c = 0; c < 5; c++) cone[2][c] = 1;

    // Preenche octaedro (padrão cruz vertical e horizontal centralizados)
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    // Preenche cruz
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    cruz[0][2] = 1;
    for (int c = 0; c < 5; c++) cruz[1][c] = 1;
    cruz[2][2] = 1;

    // Função para imprimir matriz 5x5
    void imprimir_matriz(int m[5][5], const char* nome) {
        printf("\nHabilidade: %s\n", nome);
        for (int l = 0; l < 5; l++) {
            for (int c = 0; c < 5; c++) {
                printf("%d ", m[l][c]);
            }
            printf("\n");
        }
    }

    imprimir_matriz(cone, "Cone");
    imprimir_matriz(octaedro, "Octaedro");
    imprimir_matriz(cruz, "Cruz");
}

int main() {
    printf("--- Nível Novato ---\n");
    nivel_novato();

    printf("\n--- Nível Aventureiro ---\n");
    nivel_aventureiro();

    printf("\n--- Nível Mestre ---\n");
    nivel_mestre();

    return 0;
}
