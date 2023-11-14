#ifndef SGC_H
#define SGC_H

#define MAX_PRODUTOS 100 // Defineo o número máximo de produtos
#define MAX_USUARIOS 50 // Define o número máximo de usuários

// Definição da estrutura pra produtos
struct Produto {
    char nome[100];
    double preco;
   
};

// Definição da estrutura pra usuários
struct Usuario {
    char nome[100];
    char senha[100];
    int nivelPrivilegio; // 1 para usuário convencional, 2 para administrador, xD

};

// Funções relacionadas a ações administrativas
void adicionarProduto(struct Produto estoque[], int *totalProdutos);
void listarProdutos(struct Produto estoque[], int totalProdutos);
void listarUsuarios(struct Usuario usuarios[], int totalUsuarios);
void adicionarUsuario(struct Usuario usuarios[], int *totalUsuarios);
void excluirUsuario(struct Usuario usuarios[], int *totalUsuarios);


// Funções relacionadas a ações de usuários
void fazerPedido(struct Produto estoque[], int totalProdutos, struct Usuario usuario, int* totalPedidos);

// Funções de utilidade para carregar e salvar dados em arquivos .txt
int carregarEstoque(const char *filename, struct Produto estoque[], int *totalProdutos);
int salvarEstoque(const char *filename, struct Produto estoque[], int totalProdutos);
int carregarUsuarios(const const char *filename, struct Usuario usuarios[], int *totalUsuarios);
int salvarUsuarios(const char *filename, struct Usuario usuarios[], int totalUsuarios);

#endif
