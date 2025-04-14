#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LINHAS 10
#define COLUNAS 10

// Função para verificar se é possível posicionar um navio
bool pode_posicionar(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int tamanho, int direcao) {
    // Verifica limites do tabuleiro
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
        return false;
    }

    // Verifica se todas as posições estão livres
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0) { // Horizontal
            if (coluna + i >= COLUNAS || tabuleiro[linha][coluna + i] != 0) {
                return false;
            }
        } else if (direcao == 1) { // Vertical
            if (linha + i >= LINHAS || tabuleiro[linha + i][coluna] != 0) {
                return false;
            }
        } else { // Diagonal (direita para baixo)
            if (linha + i >= LINHAS || coluna + i >= COLUNAS || tabuleiro[linha + i][coluna + i] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Função para posicionar um navio de 3 casas
void posicionar_navio_3(int tabuleiro[LINHAS][COLUNAS], int direcao) {
    int linha, coluna;
    bool posicionado = false;
    
    // Tenta posicionar até encontrar um local válido
    while (!posicionado) {
        linha = rand() % LINHAS;
        coluna = rand() % COLUNAS;
        
        if (pode_posicionar(tabuleiro, linha, coluna, 3, direcao)) {
            posicionado = true;
            
            // Marca as posições no tabuleiro com o número 3
            for (int i = 0; i < 3; i++) {
                if (direcao == 0) { // Horizontal
                    tabuleiro[linha][coluna + i] = 3;
                } else if (direcao == 1) { // Vertical
                    tabuleiro[linha + i][coluna] = 3;
                } else { // Diagonal
                    tabuleiro[linha + i][coluna + i] = 3;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Tabuleiro Batalha Naval!!!\n");
    printf("  ");
    for (int i = 0; i < COLUNAS; i++) {
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", linha[i]);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Inicializa com 0 (água)
    
    // Posiciona os navios:
    // 2 navios horizontais
    posicionar_navio_3(tabuleiro, 0); // Horizontal
    posicionar_navio_3(tabuleiro, 0); // Horizontal
    
    // 1 navio vertical
    posicionar_navio_3(tabuleiro, 1); // Vertical
    
    // 1 navio diagonal
    posicionar_navio_3(tabuleiro, 2); // Diagonal
    
    // Imprime o tabuleiro
    imprimir_tabuleiro(tabuleiro);
    
    return 0;
}