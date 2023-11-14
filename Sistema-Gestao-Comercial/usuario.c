#include <stdio.h>
#include "sgc.h"

// Função para fazer um pedido
void fazerPedido(struct Produto estoque[], int totalProdutos, struct Usuario usuario, int* totalPedidos) {
    if (totalProdutos == 0) {
        printf("Desculpe, o estoque está vazio. Não é possível fazer um pedido.\n");
        return;
    }

    // Lógica para fazer um pedido
    printf("Lista de produtos disponíveis:\n");
    listarProdutos(estoque, totalProdutos);

    int codigoProduto;
    printf("Digite o código do produto desejado: ");
    scanf("%d", &codigoProduto);

    if (codigoProduto < 1 || codigoProduto > totalProdutos) {
        printf("Código de produto inválido. Tente novamente.\n");
        return;
    }

    printf("Pedido realizado com sucesso.\n");
    (*totalPedidos)++;
}


