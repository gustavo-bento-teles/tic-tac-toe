#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

// Explicação para cada função presente neste arquivo em tic_tac_toe.c

void gerarCampo(int areaMatriz, char *campoMatriz);
void mostrarCampo(int areaMatriz, char *campoMatriz);
int verificaValidadeJogada(char playerX, char playerO, char *campoMatriz, int coordenadaX, int coordenadaY, int is_valido);
void inputJogador(char player, int coordenadaX, int coordenadaY, char *campoMatriz);
int verificaVencedor(int run, char player, char *campoMatriz);

#endif