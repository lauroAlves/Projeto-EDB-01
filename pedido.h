#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_NOME_PRATO 100

typedef struct Pedido {
    char nome[MAX_NOME_PRATO];
    struct Pedido *proximo;
} Pedido;

// Funções para manipulação dos pedidos
void adicionar_pedido(Pedido **pedidos, const char *nome);
void listar_pedidos_pendentes(Pedido *pedidos);

#endif // PEDIDO_H
