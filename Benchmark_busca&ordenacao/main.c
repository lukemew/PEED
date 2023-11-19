#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "appBusca.h"
#include "appClassificacoes.h"

int main() {
    int escolha;
    int numeroBusca;
    int quantNumeros;

    // Solicita ao usuário a quantidade de números aleatórios a serem gerados
    printf("Quantos números aleatórios deseja gerar: ");
    scanf("%d", &quantNumeros);

    // Gerar números aleatórios e armazená-los em um arquivo de texto

    int numeros[quantNumeros]; // Armazena os números gerados

    // Loop do menu
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Buscar elemento\n");
        printf("2. Classificar elementos\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Solicita ao usuário o número q precisa ser buscado
                printf("Digite o número a ser buscado: ");
                scanf("%d", &numeroBusca);

                // Chama as funções de busca e exibe o resultado de cada uma
                int posicaoLinear = buscarLinear(numeroBusca, numeros, quantNumeros);
                int posicaoSentinela = buscarSentinela(numeroBusca, numeros, quantNumeros);
                int posicaoBinaria = buscarBinaria(numeroBusca, numeros, quantNumeros);

                if (posicaoLinear != -1) {
                    printf("Número encontrado na posição %d (Busca Linear).\n", posicaoLinear);
                }

                if (posicaoSentinela != -1) {
                    printf("Número encontrado na posição %d (Busca Sentinela).\n", posicaoSentinela);
                }

                if (posicaoBinaria != -1) {
                    printf("Número encontrado na posição %d (Busca Binária).\n", posicaoBinaria);
                }

                break;
            case 2:
                // Chamar as funções de classificação
                insertionSort(numeros, quantNumeros);
                bubbleSort(numeros, quantNumeros);
                sortWithQuickSort(numeros, quantNumeros);

                // Exibir os números ordenados
                printf("Números ordenados: ");
                for (int i = 0; i < quantNumeros; i++) {
                    printf("%d ", numeros[i]);
                }
                printf("\n");

                break;
            case 3:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
