#include "tic_tac_toe.h"
#include "game.h"
#include "utils.h"
#include <stdio.h>

// Função que une tudo e inicia o jogo
void iniciarJogo() {
    // Área total da matriz (3x3)
    int areaMatriz = 9;

    // Array que contém a matriz
    char *campoMatriz = alocarMemoria(areaMatriz);

    // Variáveis de controle de jogadas
    char player = 'X';
    char ultimoPlayer = player;
    int coordenadaX;
    int coordenadaY;

    // Caracteres usados para marcar algum espaço no jogo da velha
    char playerX = 'X';
    char playerO = 'O';

    // Variáveis para controlar o jogo em si
    int rodada = 0;
    int validadeJogada;
    int run = 1;

    // Gera a matriz com apenas '-' na matriz
    gerarCampo(areaMatriz, campoMatriz);

    // Exibe a matriz
    mostrarCampo(areaMatriz, campoMatriz);

    printf("Começa com o player: %c\n", player);

    // Looping principal
    while (run) {
        rodada++;
        printf("%d\n", rodada);

        // Obtem e avalia se as coordenadas recebidas são válidas
        do {
            printf("Player %c, digite a coordenada x (0-2): ", player);
            if (scanf("%d", &coordenadaX) != 1 || coordenadaX < 0 || coordenadaX > 2) {
                printf("\nEntrada inválida. Tente novamente.\n");
                continue;
            }

            printf("Player %c, digite a coordenada y (0-2): ", player);
            if (scanf("%d", &coordenadaY) != 1 || coordenadaY < 0 || coordenadaY > 2) {
                printf("\nEntrada inválida. Tente novamente.\n");
                continue;
            }

            // Verifica se a jogada é válida
            validadeJogada = verificaValidadeJogada(playerX, playerO, campoMatriz, coordenadaX, coordenadaY, validadeJogada);

            if (validadeJogada != 1) {
                printf("\nJogada inválida. Escolha outro lugar.\n");
            }

        } while (validadeJogada != 1);

        // Realiza a marcação do 'X' ou 'O' em alguma coordenada da matriz
        inputJogador(player, coordenadaX, coordenadaY, campoMatriz);

        // Verifica qual foi o último jogador a jogar, para fazer a troca de turnos
        if (ultimoPlayer == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }

        // Exibe a matriz novamente
        mostrarCampo(areaMatriz, campoMatriz);

        // Verifica se alguém já venceu e armazena isso em uma variável
        int running = verificaVencedor(run, ultimoPlayer, campoMatriz);

        // Verifica se houve um empate, verificando se o número de rodadas é equivalente a área da matriz
        if (rodada == areaMatriz) {
            printf("Ocorreu um empate!!\n");
            running = 0;
        }

        // Realiza a troca de player
        ultimoPlayer = player;

        // Atribui o valor de runnig para run
        run = running;
    }

    // Limpa o espaço alocado para a matiz
    limparMemoria(campoMatriz);
}