#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Adiciona um pedido à lista de pedidos
void adicionar_pedido(Pedido **pedidos, const char *nome) {
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo pedido.\n");
        exit(1);
    }
    strncpy(novo_pedido->nome, nome, MAX_NOME_PRATO);
    novo_pedido->nome[MAX_NOME_PRATO - 1] = '\0';
    novo_pedido->proximo = *pedidos;
    *pedidos = novo_pedido;
}

// Lista todos os pedidos pendentes
void listar_pedidos_pendentes(Pedido *pedidos) {
    Pedido *current = pedidos;
    while (current != NULL) {
        printf("%s\n", current->nome);
        current = current->proximo;
    }
}
