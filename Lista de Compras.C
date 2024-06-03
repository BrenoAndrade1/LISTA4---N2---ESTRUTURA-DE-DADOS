#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char nome[100];
    int quantidade;
    struct Item* prox;
} Item;

typedef struct {
    Item* cabeca;
} ListaCompras;

void inicializarLista(ListaCompras* lista);
void inserirItem(ListaCompras* lista, char* nome, int quantidade);
void removerItem(ListaCompras* lista, char* nome);
Item* consultarItem(ListaCompras* lista, char* nome);
void exibirLista(ListaCompras* lista);
void exibirMenu();

int main() {
    ListaCompras lista;
    inicializarLista(&lista);
    int opcao, quantidade;
    char nome[100];

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]s", nome);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                inserirItem(&lista, nome, quantidade);
                break;
            case 2:
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]s", nome);
                removerItem(&lista, nome);
                break;
            case 3:
                printf("Digite o nome do produto a ser consultado: ");
                scanf(" %[^\n]s", nome);
                Item* item = consultarItem(&lista, nome);
                if (item != NULL) {
                    printf("Produto encontrado: %s, Quantidade: %d\n", item->nome, item->quantidade);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            case 4:
                exibirLista(&lista);
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Implementações das funções
