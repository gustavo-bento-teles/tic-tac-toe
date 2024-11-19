#include <stdio.h>
#include "tic_tac_toe.h"
#include "utils.h"

// Função que gera o campo (matriz do jogo), colocando '-' em cada espaço presente em um array
void gerarCampo(int areaMatriz, char *campoMatriz) {
    for (int i = 0; i < areaMatriz; i++) {
        campoMatriz[i] = '-';
    }
}

// Exibe o campo de forma organizada na tela, iterando sobre o array e verificando se está na última linha
void mostrarCampo(int areaMatriz, char *campoMatriz) {
    for (int i = 0; i < areaMatriz; i++) {
        printf(" %c ", campoMatriz[i]);

        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

// Verifica a validade de uma jogada, ou seja, se é permitida, por observar se há 'X' ou 'O' ali
int verificaValidadeJogada(char playerX, char playerO, char *campoMatriz, int coordenadaX, int coordenadaY, int is_valido) {
    int indice_matriz = (coordenadaY * 3) + coordenadaX;

    if (playerX == campoMatriz[indice_matriz] || playerO == campoMatriz[indice_matriz]) {
        is_valido = 0;

    } else if (playerX != campoMatriz[indice_matriz] || playerO == campoMatriz[indice_matriz]) {
        is_valido = 1;
    }
    
    return is_valido;
}

// Realiza a marcação do 'X' ou do 'O' dentro do array a partir das coordenadas enviadas e de uma fórmula
void inputJogador(char player, int coordendadaX, int coordenadaY, char *campoMatriz) {
    int indice_matriz = (coordenadaY * 3) + coordendadaX;

    if (player == 'X') {
        campoMatriz[indice_matriz] = 'X';
    } else if (player == 'O') {
        campoMatriz[indice_matriz] = 'O';
    }

}

// Verifica se alguém já ganhou por analisar se os índices obtêm uma mesma informação guardada
int verificaVencedor(int run, char player, char *campoMatriz) {

    // Horizontal
    if (player == campoMatriz[0] && player == campoMatriz[1] && player == campoMatriz[2]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else if (player == campoMatriz[3] && player == campoMatriz[4] && player == campoMatriz[5]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else if (player == campoMatriz[6] && player == campoMatriz[7] && player == campoMatriz[8]) {
        printf("O player %c venceu!\n", player);
        run = 0;
    
    // Vertical
    } else if (player == campoMatriz[0] && player == campoMatriz[3] && player == campoMatriz[6]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else if (player == campoMatriz[1] && player == campoMatriz[4] && player == campoMatriz[7]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else if (player == campoMatriz[2] && player == campoMatriz[5] && player == campoMatriz[8]) {
        printf("O player %c venceu!\n", player);
        run = 0;
    
    // Diagonal
    } else if (player == campoMatriz[0] && player == campoMatriz[4] && player == campoMatriz[8]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else if (player == campoMatriz[2] && player == campoMatriz[4] && player == campoMatriz[6]) {
        printf("O player %c venceu!\n", player);
        run = 0;

    } else {
        run = 1;
    }

    return run;
}