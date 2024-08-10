#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pedido.h"
#include "fila.h"

int main() {
    Pedido *pedidos_pendentes = NULL;
    Fila *fila_de_processamento = criar_fila();
    if (fila_de_processamento == NULL) {
        fprintf(stderr, "Erro ao criar a fila de processamento.\n");
        return 1;
    }

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Pedido\n");
        printf("2. Remover Pedido\n");
        printf("3. Processar Pedido\n");
        printf("4. Listar Pedidos Pendentes\n");
        printf("5. Listar Pedidos em Processamento\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir newline

        switch (opcao) {
            case 1:
                adicionar_pedido_menu(&pedidos_pendentes);
                break;

            case 2:
                remover_pedido_menu(&pedidos_pendentes);
                break;

            case 3:
                if (pedidos_pendentes != NULL) {
                    Pedido *pedido_para_processar = pedidos_pendentes;
                    pedidos_pendentes = pedidos_pendentes->proximo;
                    pedido_para_processar->proximo = NULL;
                    adicionar_a_fila(fila_de_processamento, pedido_para_processar);
                } else {
                    printf("Nenhum pedido pendente para processar.\n");
                }
                break;

            case 4:
                printf("Pedidos Pendentes:\n");
                listar_pedidos_pendentes(pedidos_pendentes);
                break;

            case 5:
                printf("Pedidos em Processamento:\n");
                listar_pedidos_em_processamento(fila_de_processamento);
                break;

            case 6:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    // Liberar memória
    while (pedidos_pendentes != NULL) {
        Pedido *temp = pedidos_pendentes;
        pedidos_pendentes = pedidos_pendentes->proximo;
        free(temp);
    }

    while (fila_de_processamento->inicio != NULL) {
        Pedido *temp = remover_da_fila(fila_de_processamento);
        free(temp);
    }

    free(fila_de_processamento);

    return 0;
}
