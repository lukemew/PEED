#include <stdio.h>
#include <string.h>
#include "sgc.h"

int main() {
    struct Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0;
    struct Usuario usuarios[MAX_USUARIOS];
    int totalUsuarios = 0;
    int opcao;

    // Carrega os dados do arquvo ao iniciar o programa
    carregarEstoque("estoque.txt", estoque, &totalProdutos);
    carregarUsuarios("usuarios.txt", usuarios, &totalUsuarios);

    printf("Seja bem-vindo ao Sistema de Gestao Comercial (SGC)!!\n");

    // Autenticação de admin
    char senhaAdmin[100];
    printf("Digite a senha de administrador: ");
    scanf("%s", senhaAdmin);

    // SENHA: "isaac"
    if (strcmp(senhaAdmin, "isaac") == 0) { // essa funçao compara a senha inserida com a string 'isaac'
        printf("Autenticacao bem-sucedida como administrador.\n");
        do {
            // Menu para o admin
            printf("---------Menu de Administrador:----------\n");
            printf("1. Adicionar produto\n");
            printf("2. Listar produtos\n");
            printf("3. Adicionar usuario\n");
            printf("4. Excluir usuario\n");
            printf("5. Sair\n");
            printf("Escolha uma opccao: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    adicionarProduto(estoque, &totalProdutos);
                    break;
                case 2:
                    listarProdutos(estoque, totalProdutos);
                    break;
                case 3:
                    adicionarUsuario(usuarios, &totalUsuarios);
                    break;
                case 4:
                    excluirUsuario(usuarios, &totalUsuarios);
                    break;
                case 5:
                    // Função para salvar os dados e quitar do programa
                    salvarEstoque("estoque.txt", estoque, totalProdutos);
                    salvarUsuarios("usuarios.txt", usuarios, totalUsuarios);
                    break;
                default:
                    printf("Opção invaalida. Tente novamente.\n");
            }
        } while (opcao != 5);
    } else {
        printf("Senha de administrador incorreta. Você vai ser tratado como um usuario convencional.\n");
        do {
            // Menu para usuários convencionais
            printf("----------Menu de Usuario Convencional:-----------\n");
            printf("1. Fazer pedido\n");
            printf("2. Listar produtos\n");
            printf("3. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    fazerPedido(estoque, totalProdutos, usuarios[0], &totalProdutos);
                    break;
                case 2:
                    listarProdutos(estoque, totalProdutos);
                    break;
                case 3:
                    // Sair do programa
                    break;
                default:
                    printf("Opção invalida. Tente novamente.\n");
            }
        } while (opcao != 3);
    }
    return 0;
}
