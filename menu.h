#ifndef MENU_H
#define MENU_H

#include "pedido.h"

// Funções para exibição dos menus
void exibir_entradas();
void exibir_pratos_principais();
void exibir_sobremesas();
void exibir_menu_principal();
void adicionar_pedido_menu(Pedido **pedidos_pendentes);
void remover_pedido_menu(Pedido **pedidos_pendentes);

#endif // MENU_H
