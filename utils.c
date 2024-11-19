#include <stdlib.h>
#include "utils.h"

// Função para abrir/alocar um espaço na memória
char* alocarMemoria(int dataSize) {
    char *pointer = (char *)malloc(dataSize * sizeof(char));

    return pointer;
}

// Função para limpar/liberar um espaço aberto na memória
void limparMemoria(char *pointer) {
    free(pointer);
}