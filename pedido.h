#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_NOME_PRATO 50

typedef struct Pedido {
    char nome[MAX_NOME_PRATO];
    struct Pedido *proximo;
} Pedido;

typedef struct Fila {
    Pedido *inicio;
    Pedido *fim;
} Fila;

// Funções para gerenciar pedidos
void adicionar_pedido(Pedido **pedidos_pendentes, const char *nome);
void listar_pedidos_pendentes(Pedido *pedidos_pendentes);
void listar_pedidos_em_processamento(Fila *fila);

// Funções para gerenciar a fila
Fila *criar_fila();
void adicionar_a_fila(Fila *fila, Pedido *pedido);
Pedido *remover_da_fila(Fila *fila);

#endif // PEDIDO_H
