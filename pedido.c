#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Adicionar um pedido à lista de pedidos pendentes
void adicionar_pedido(Pedido **pedidos_pendentes, const char *nome) {
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo pedido.\n");
        return;
    }
    strncpy(novo_pedido->nome, nome, MAX_NOME_PRATO);
    novo_pedido->proximo = *pedidos_pendentes;
    *pedidos_pendentes = novo_pedido;
}

// Listar pedidos pendentes
void listar_pedidos_pendentes(Pedido *pedidos_pendentes) {
    Pedido *atual = pedidos_pendentes;
    if (atual == NULL) {
        printf("Nenhum pedido pendente.\n");
        return;
    }
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

// Listar pedidos em processamento
void listar_pedidos_em_processamento(Fila *fila) {
    Pedido *atual = fila->inicio;
    if (atual == NULL) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

// Criar uma nova fila
Fila *criar_fila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// Adicionar um pedido à fila
void adicionar_a_fila(Fila *fila, Pedido *pedido) {
    if (fila->fim == NULL) {
        fila->inicio = pedido;
        fila->fim = pedido;
    } else {
        fila->fim->proximo = pedido;
        fila->fim = pedido;
    }
    pedido->proximo = NULL;
}

// Remover um pedido da fila
Pedido *remover_da_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    Pedido *pedido_removido = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    return pedido_removido;
}
