#include <stdio.h>
#include "sgc.h"

// Função para adicionar um produto ao estoque
void adicionarProduto(struct Produto estoque[], int* totalProdutos) {
    if (*totalProdutos < MAX_PRODUTOS) {
        // Lógica para adicionar um novo produto ao estoque
        printf("Digite o nome do produto: ");
        scanf("%s", estoque[*totalProdutos].nome);

        printf("Digite o valor do produto: ");
        scanf("%lf", &estoque[*totalProdutos].preco);

        (*totalProdutos)++;
        printf("Produto adicionado com sucesso.\n");
    } else {
        printf("O estoque esta cheio. Nao eh possível adicionar mais produtos.\n");
    }
}

// Função para listar produtos
void listarProdutos(struct Produto estoque[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto está disponivel no estoque.\n");
        return;
    }

    printf("Produtos disponiveis no estoque:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Codigo: %d\n", i + 1);
        printf("Nome: %s\n", estoque[i].nome);
        printf("Preco: %.2f\n", estoque[i].preco);
        printf("\n");
    }
}

// Função para listar usuários
void listarUsuarios(struct Usuario usuarios[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("Nenhum usuário registrado.\n");
        return;
    }

    printf("Usuarios registrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Nivel de privilegio: %d\n", usuarios[i].nivelPrivilegio);
        printf("\n");
    }
}

void adicionarUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios >= MAX_USUARIOS) {
        printf("Não é possível adicionar mais usuários. Limite atingido.\n");
        return;
    }

    struct Usuario novoUsuario;
    printf("Nome do novo usuário: ");
    scanf("%s", novoUsuario.nome);
    printf("Senha: ");
    scanf("%s", novoUsuario.senha);
    printf("Nivel de privilegio (1 para usuário convencional, 2 para administrador, por exemplo): ");
    scanf("%d", &novoUsuario.nivelPrivilegio);

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuario adicionado com sucesso!!\n");
}
// Outras funções relacionadas a ações administrativas
void excluirUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios == 0) {
        printf("Nenhum usuário registrado para exclusao.\n");
        return;
    }

    printf("Lista de Usuários:\n");
    for (int i = 0; i < *totalUsuarios; i++) {
        printf("Código: %d\n", i + 1);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("\n");
    }

    int codigoExcluir;
    printf("Digite o codigo do usuario a ser excluido: ");
    scanf("%d", &codigoExcluir);

    if (codigoExcluir < 1 || codigoExcluir > *totalUsuarios) {
        printf("Codigo invalido. Nenhum usuario foi excluido.\n");
    } else {
        // Faz a exclusão dos usuários e atualiza o total de usuários
        for (int i = codigoExcluir - 1; i < *totalUsuarios - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        (*totalUsuarios)--;
        printf("Usuário excluido com sucesso!!\n");
    }
}


// Funções de salvamento e carregamento dos arquivos .txt
//Função pra atualizar o estoque
int salvarEstoque(const char *filename, struct Produto estoque[], int totalProdutos) {
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", filename);
        return 0;
    }

    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%s %.2f\n", estoque[i].nome, estoque[i].preco);
    }

    fclose(arquivo);
    return 1;
}

// Função pra salvar usuarios
int salvarUsuarios(const char *filename, struct Usuario usuarios[], int totalUsuarios) {
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", filename);
        return 0;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        fprintf(arquivo, "%s %s %d\n", usuarios[i].nome, usuarios[i].senha, usuarios[i].nivelPrivilegio);
    }

    fclose(arquivo);
    return 1;
}

// Função pra carregar dados de estoque do arquivo
int carregarEstoque(const char *filename, struct Produto estoque[], int *totalProdutos) {
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para leitura.\n", filename);
        return 0; 
    }

    *totalProdutos = 0;


    while (*totalProdutos < MAX_PRODUTOS && fscanf(arquivo, "%99s %lf\n", estoque[*totalProdutos].nome, &estoque[*totalProdutos].preco) == 2) {
        (*totalProdutos)++;
    }

    fclose(arquivo);
    return 1; 
}

// Função para carregar dados de usuários do arquivo
int carregarUsuarios(const char *filename, struct Usuario usuarios[], int *totalUsuarios) {
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para leitura.\n", filename);
        return 0; 
    }

    *totalUsuarios = 0;


    while (*totalUsuarios < MAX_USUARIOS && fscanf(arquivo, "%99s %99s %d\n", usuarios[*totalUsuarios].nome, usuarios[*totalUsuarios].senha, &usuarios[*totalUsuarios].nivelPrivilegio) == 3) {
        (*totalUsuarios)++;
    }

    fclose(arquivo);
    return 1; 
}

