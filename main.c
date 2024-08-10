#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

// Declarações das funções
void exibir_entradas();
void exibir_pratos_principais();
void exibir_sobremesas();
void exibir_menu_principal();
void adicionar_pedido_menu(Pedido **pedidos_pendentes);
void remover_pedido_menu(Pedido **pedidos_pendentes);

// Função para exibir o cardápio de entradas
void exibir_entradas() {
    printf("\nEntradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n");
}

// Função para exibir o cardápio de pratos principais
void exibir_pratos_principais() {
    printf("\nPratos Principais:\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n");
}

// Função para exibir o cardápio de sobremesas
void exibir_sobremesas() {
    printf("\nSobremesas:\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n");
}

// Função para exibir o menu principal
void exibir_menu_principal() {
    printf("\nMenu:\n");
    printf("1. Entradas\n");
    printf("2. Pratos Principais\n");
    printf("3. Sobremesas\n");
}

// Função para adicionar um pedido com base na categoria e item escolhido
void adicionar_pedido_menu(Pedido **pedidos_pendentes) {
    int opcao_categoria, opcao_item;
    char nome[MAX_NOME_PRATO];

    exibir_menu_principal();
    printf("\nEscolha uma categoria (Digite o número correspondente): ");
    scanf("%d", &opcao_categoria);
    getchar(); // Consumir newline

    switch (opcao_categoria) {
        case 1:
            exibir_entradas();
            printf("\nEscolha um item de Entradas (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            switch (opcao_item) {
                case 1: strncpy(nome, "Sopa de Cebola", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Salada Caesar", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Bruschetta", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Carpaccio de Carne", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Camarão ao Alho", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        case 2:
            exibir_pratos_principais();
            printf("\nEscolha um item de Pratos Principais (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            switch (opcao_item) {
                case 1: strncpy(nome, "Lasanha à Bolonhesa", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Filé Mignon com Fritas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Frango Grelhado com Legumes", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Bacalhau à Gomes de Sá", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Risoto de Cogumelos", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        case 3:
            exibir_sobremesas();
            printf("\nEscolha um item de Sobremesas (Digite o número correspondente): ");
            scanf("%d", &opcao_item);
            getchar(); // Consumir newline

            switch (opcao_item) {
                case 1: strncpy(nome, "Tiramisu", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Cheesecake de Frutas Vermelhas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Mousse de Chocolate", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Pudim de Leite", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Sorvete de Baunilha com Calda de Morango", MAX_NOME_PRATO); break;
                default: printf("Opção inválida.\n"); return;
            }
            break;

        default:
            printf("Categoria inválida.\n");
            return;
    }

    adicionar_pedido(pedidos_pendentes, nome);
}

// Função para remover um pedido com base na categoria e item escolhido
void remover_pedido_menu(Pedido **pedidos_pendentes) {
    int opcao_categoria, opcao_item;
    char nome[MAX_NOME_PRATO];
    int item_encontrado = 0;

    exibir_menu_principal();
    printf("\nQual tipo de prato você deseja remover? (Digite o número correspondente): ");
    scanf("%d", &opcao_categoria);
    getchar(); // Consumir newline

    switch (opcao_categoria) {
        case 1:
            exibir_entradas();
            break;
        case 2:
            exibir_pratos_principais();
            break;
        case 3:
            exibir_sobremesas();
            break;
        default:
            printf("Categoria inválida.\n");
            return;
    }

    printf("\nEscolha um item para remover (Digite o número correspondente): ");
    scanf("%d", &opcao_item);
    getchar(); // Consumir newline

    switch (opcao_categoria) {
        case 1:
            switch (opcao_item) {
                case 1: strncpy(nome, "Sopa de Cebola", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Salada Caesar", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Bruschetta", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Carpaccio de Carne", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Camarão ao Alho", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
        case 2:
            switch (opcao_item) {
                case 1: strncpy(nome, "Lasanha à Bolonhesa", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Filé Mignon com Fritas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Frango Grelhado com Legumes", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Bacalhau à Gomes de Sá", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Risoto de Cogumelos", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
        case 3:
            switch (opcao_item) {
                case 1: strncpy(nome, "Tiramisu", MAX_NOME_PRATO); break;
                case 2: strncpy(nome, "Cheesecake de Frutas Vermelhas", MAX_NOME_PRATO); break;
                case 3: strncpy(nome, "Mousse de Chocolate", MAX_NOME_PRATO); break;
                case 4: strncpy(nome, "Pudim de Leite", MAX_NOME_PRATO); break;
                case 5: strncpy(nome, "Sorvete de Baunilha com Calda de Morango", MAX_NOME_PRATO); break;
                default: printf("Item inválido.\n"); return;
            }
            break;
    }

    // Verificar se o item existe na lista de pedidos pendentes
    Pedido *current = *pedidos_pendentes;
    Pedido *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->nome, nome) == 0) {
            item_encontrado = 1;
            break;
        }
        prev = current;
        current = current->proximo;
    }

    if (!item_encontrado) {
        printf("Você não selecionou este prato.\n");
        return;
    }

    // Confirmar remoção
    char confirmacao;
    printf("Deseja remover este prato? (s/n): ");
    scanf("%c", &confirmacao);
    getchar(); // Consumir newline

    if (confirmacao == 's' || confirmacao == 'S') {
        if (prev == NULL) {
            *pedidos_pendentes = (*pedidos_pendentes)->proximo;
        } else {
            prev->proximo = current->proximo;
        }
        free(current);
        printf("Prato removido com sucesso.\n");
    } else {
        printf("Prato não removido.\n");
    }
}

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
