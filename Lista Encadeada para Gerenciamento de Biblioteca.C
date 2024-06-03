#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do livro
typedef struct Livro {
    char autor[100];
    char titulo[100];
    char editora[100];
    int ano;
    struct Livro* prox;
} Livro;

// Funções de manipulação da lista
Livro* inserirLivroOrdenado(Livro* head, Livro* novoLivro);
Livro* removerLivro(Livro* head, char* titulo);
void alterarLivro(Livro* head, char* titulo);
Livro* buscarLivroPorNome(Livro* head, char* titulo);
Livro* buscarLivroPorAutor(Livro* head, char* autor);
void exibirMenu();
void imprimirLivros(Livro* head);

int main() {
    Livro* biblioteca = NULL;
    int opcao;
    char titulo[100], autor[100];
    Livro novoLivro;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserção
                printf("Digite o autor: ");
                scanf("%s", novoLivro.autor);
                printf("Digite o título: ");
                scanf("%s", novoLivro.titulo);
                printf("Digite a editora: ");
                scanf("%s", novoLivro.editora);
                printf("Digite o ano: ");
                scanf("%d", &novoLivro.ano);
                biblioteca = inserirLivroOrdenado(biblioteca, &novoLivro);
                break;
            case 2:
                // Remoção
                printf("Digite o título do livro a ser removido: ");
                scanf("%s", titulo);
                biblioteca = removerLivro(biblioteca, titulo);
                break;
            case 3:
                // Alteração
                printf("Digite o título do livro a ser alterado: ");
                scanf("%s", titulo);
                alterarLivro(biblioteca, titulo);
                break;
            case 4:
                // Busca por nome
                printf("Digite o título do livro a ser buscado: ");
                scanf("%s", titulo);
                Livro* livroEncontrado = buscarLivroPorNome(biblioteca, titulo);
                if (livroEncontrado != NULL) {
                    printf("Livro encontrado: %s por %s\n", livroEncontrado->titulo, livroEncontrado->autor);
                } else {
                    printf("Livro não encontrado.\n");
                }
                break;
            case 5:
                // Busca por autor
                printf("Digite o autor do livro a ser buscado: ");
                scanf("%s", autor);
                Livro* livrosEncontrados = buscarLivroPorAutor(biblioteca, autor);
                if (livrosEncontrados != NULL) {
                    imprimirLivros(livrosEncontrados);
                } else {
                    printf("Livros não encontrados.\n");
                }
                break;
            case 6:
                // Exibir todos os livros
                imprimirLivros(biblioteca);
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Implementações das funções
