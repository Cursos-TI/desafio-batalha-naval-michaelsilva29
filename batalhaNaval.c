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

// Superpoder Cone (5 casas)
void habilidade_cone(int tabuleiro[LINHAS][COLUNAS]) {
    int linha, coluna, direcao;
    bool posicionado = false;
    
    printf("\nAtivando superpoder CONE!\n");
    
    while (!posicionado) {
        linha = rand() % LINHAS;
        coluna = rand() % COLUNAS;
        direcao = rand() % 4; // 0: direita, 1: baixo, 2: esquerda, 3: cima
        
        // Verifica se a posição central está livre
        if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS && 
            tabuleiro[linha][coluna] == 0) {
            
            posicionado = true;
            tabuleiro[linha][coluna] = 5; // Centro do cone
            
            // Adiciona as casas adjacentes conforme a direção
            switch (direcao) {
                case 0: // Direita
                    if (coluna + 1 < COLUNAS) tabuleiro[linha][coluna + 1] = 5;
                    if (linha > 0 && coluna + 1 < COLUNAS) tabuleiro[linha - 1][coluna + 1] = 5;
                    if (linha + 1 < LINHAS && coluna + 1 < COLUNAS) tabuleiro[linha + 1][coluna + 1] = 5;
                    if (coluna + 2 < COLUNAS) tabuleiro[linha][coluna + 2] = 5;
                    break;
                case 1: // Baixo
                    if (linha + 1 < LINHAS) tabuleiro[linha + 1][coluna] = 5;
                    if (linha + 1 < LINHAS && coluna > 0) tabuleiro[linha + 1][coluna - 1] = 5;
                    if (linha + 1 < LINHAS && coluna + 1 < COLUNAS) tabuleiro[linha + 1][coluna + 1] = 5;
                    if (linha + 2 < LINHAS) tabuleiro[linha + 2][coluna] = 5;
                    break;
                case 2: // Esquerda
                    if (coluna > 0) tabuleiro[linha][coluna - 1] = 5;
                    if (linha > 0 && coluna > 0) tabuleiro[linha - 1][coluna - 1] = 5;
                    if (linha + 1 < LINHAS && coluna > 0) tabuleiro[linha + 1][coluna - 1] = 5;
                    if (coluna > 1) tabuleiro[linha][coluna - 2] = 5;
                    break;
                case 3: // Cima
                    if (linha > 0) tabuleiro[linha - 1][coluna] = 5;
                    if (linha > 0 && coluna > 0) tabuleiro[linha - 1][coluna - 1] = 5;
                    if (linha > 0 && coluna + 1 < COLUNAS) tabuleiro[linha - 1][coluna + 1] = 5;
                    if (linha > 1) tabuleiro[linha - 2][coluna] = 5;
                    break;
            }
        }
    }
}

// Superpoder Cruz (5 casas)
void habilidade_cruz(int tabuleiro[LINHAS][COLUNAS]) {
    int linha, coluna;
    bool posicionado = false;
    
    printf("\nAtivando superpoder CRUZ!\n");
    
    while (!posicionado) {
        linha = 1 + rand() % (LINHAS - 2); // Evita bordas
        coluna = 1 + rand() % (COLUNAS - 2); // Evita bordas
        
        // Verifica se a posição central está livre
        if (tabuleiro[linha][coluna] == 0) {
            posicionado = true;
            
            // Marca a cruz (5 casas)
            tabuleiro[linha][coluna] = 5;    // Centro
            tabuleiro[linha - 1][coluna] = 5; // Cima
            tabuleiro[linha + 1][coluna] = 5; // Baixo
            tabuleiro[linha][coluna - 1] = 5; // Esquerda
            tabuleiro[linha][coluna + 1] = 5; // Direita
        }
    }
}

// Superpoder Octaedro (8 casas em forma de diamante)
void habilidade_octaedro(int tabuleiro[LINHAS][COLUNAS]) {
    int linha, coluna;
    bool posicionado = false;
    
    printf("\nAtivando superpoder OCTAEDRO!\n");
    
    while (!posicionado) {
        linha = 2 + rand() % (LINHAS - 4); // Precisa de mais espaço
        coluna = 2 + rand() % (COLUNAS - 4); // Precisa de mais espaço
        
        // Verifica se todas as posições estão livres
        if (tabuleiro[linha][coluna] == 0 &&
            tabuleiro[linha - 1][coluna] == 0 &&
            tabuleiro[linha + 1][coluna] == 0 &&
            tabuleiro[linha][coluna - 1] == 0 &&
            tabuleiro[linha][coluna + 1] == 0 &&
            tabuleiro[linha - 1][coluna - 1] == 0 &&
            tabuleiro[linha - 1][coluna + 1] == 0 &&
            tabuleiro[linha + 1][coluna - 1] == 0 &&
            tabuleiro[linha + 1][coluna + 1] == 0) {
            
            posicionado = true;
            
            // Marca o octaedro (diamante)
            tabuleiro[linha][coluna] = 5;       // Centro
            tabuleiro[linha - 1][coluna] = 5;   // Cima
            tabuleiro[linha + 1][coluna] = 5;   // Baixo
            tabuleiro[linha][coluna - 1] = 5;   // Esquerda
            tabuleiro[linha][coluna + 1] = 5;   // Direita
            tabuleiro[linha - 1][coluna - 1] = 5; // Diagonal superior esquerda
            tabuleiro[linha - 1][coluna + 1] = 5; // Diagonal superior direita
            tabuleiro[linha + 1][coluna - 1] = 5; // Diagonal inferior esquerda
            tabuleiro[linha + 1][coluna + 1] = 5; // Diagonal inferior direita
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("\nTabuleiro Batalha Naval!!!\n");
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

    // Imprime o tabuleiro inicial
    imprimir_tabuleiro(tabuleiro);
    
    // Ativa os superpoderes
    habilidade_cone(tabuleiro);
    habilidade_cruz(tabuleiro);
    habilidade_octaedro(tabuleiro);
    
    // Imprime o tabuleiro com os superpoderes
    imprimir_tabuleiro(tabuleiro);
    
    
    return 0;
}