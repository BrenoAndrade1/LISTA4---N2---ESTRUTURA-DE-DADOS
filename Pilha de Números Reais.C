#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    float dado;
    struct Nodo* prox;
} Nodo;

typedef struct Pilha {
    Nodo* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
void push(Pilha* pilha, float valor);
float pop(Pilha* pilha);
int estaVazia(Pilha* pilha);
void exibirPilha(Pilha* pilha);
void exibirMenu();

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    int opcao;
    float valor;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número real para empilhar: ");
                scanf("%f", &valor);
                push(&pilha, valor);
                break;
            case 2:
                if (!estaVazia(&pilha)) {
                    valor = pop(&pilha);
                    printf("Valor desempilhado: %.2f\n", valor);
                } else {
                    printf("A pilha está vazia.\n");
                }
                break;
            case 3:
                exibirPilha(&pilha);
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Implementações das funções
