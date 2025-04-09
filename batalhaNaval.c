#include <stdio.h>


int main() {
    // Array com as letras das colunas (A-J)
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Array com os números das linhas (1-10)
    // Observação: seria melhor declarar como int, pois char armazena caracteres
    int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Matriz 10x10 que representa o tabuleiro do jogo
    // 0 = água, outros números representam navios (no caso, 3 = navio)
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 0
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 1
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linha 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // Linha 9
    };

    printf("Batalha Naval!!!\n");

    // Imprime o cabeçalho com as letras das colunas (A-J)
    for (int i = 0; i < 10; i++) {
        printf(" ");
        printf("%c", coluna[i]);
    }
    printf("\n");
    
    // Imprime o tabuleiro completo com números das linhas
    for (int i = 0; i < 10; i++) { 
        // Imprime o número da linha
        printf("%d ", linha[i]);
        
        // Imprime o conteúdo de cada célula do tabuleiro
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }
    
    // Posicionamento dos navios no tabuleiro
    // Navio horizontal: posições (1,1), (1,2), (1,3)
    tabuleiro[1][1] = 3; // 3 representa parte de um navio
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    
    // Navio vertical: posições (0,5), (1,5), (2,5)
    tabuleiro[0][5] = 3;
    tabuleiro[1][5] = 3;
    tabuleiro[2][5] = 3;

    printf("\n");

    printf("Posicionamento dos Navios!!!\n");
    
    // Imprime novamente o cabeçalho com as letras das colunas
    for (int i = 0; i < 10; i++) {
        printf(" ");
        printf("%c", coluna[i]);
    }
    printf("\n");
    
    // Imprime o tabuleiro novamente, agora com os navios posicionados
    for (int i = 0; i < 10; i++) { 
        printf("%d ", linha[i]);
        
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0; // Fim do programa
}