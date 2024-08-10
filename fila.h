#ifndef FILA_H
#define FILA_H

#include "pedido.h"

typedef struct Fila {
    Pedido *inicio;
    Pedido *fim;
} Fila;

// Funções para manipulação da fila
Fila *criar_fila();
void adicionar_a_fila(Fila *fila, Pedido *pedido);
Pedido *remover_da_fila(Fila *fila);
void listar_pedidos_em_processamento(Fila *fila);

#endif // FILA_H
