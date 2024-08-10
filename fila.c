#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include "fila.h"

// Cria uma nova fila
Fila *criar_fila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL) {
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// Adiciona um pedido à fila
void adicionar_a_fila(Fila *fila, Pedido *pedido) {
    if (fila->fim == NULL) {
        fila->inicio = pedido;
        fila->fim = pedido;
    } else {
        fila->fim->proximo = pedido;
        fila->fim = pedido;
    }
}

// Remove um pedido da fila
Pedido *remover_da_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    Pedido *pedido = fila->inicio;
    fila->inicio = pedido->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    return pedido;
}

// Lista os pedidos em processamento
void listar_pedidos_em_processamento(Fila *fila) {
    Pedido *current = fila->inicio;
    while (current != NULL) {
        printf("%s\n", current->nome);
        current = current->proximo;
    }
}
