#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Processo {
    int id;
    char descricao[100];
    struct Processo* prox;
} Processo;

typedef struct Pilha {
    Processo* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
void push(Pilha* pilha, int id, char* descricao);
Processo* pop(Pilha* pilha);
int estaVazia(Pilha* pilha);
void exibirPilha(Pilha* pilha);
void exibirMenu();

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    int opcao, id;
    char descricao[100];

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador do processo: ");
                scanf("%d", &id);
                printf("Digite a descrição do processo: ");
                scanf(" %[^\n]s", descricao);
                push(&pilha, id, descricao);
                break;
            case 2:
                if (!estaVazia(&pilha)) {
                    Processo* processo = pop(&pilha);
                    printf("Removido o processo #%d - %s\n", processo->id, processo->descricao);
                    free(processo);
                } else {
                    printf("A pilha está vazia.\n");
                }
                break;
            case 3:
                exibirPilha(&pilha);
                break;
        }
    } while (opcao != 0);

    while (!estaVazia(&pilha)) {
        Processo* processo = pop(&pilha);
        free(processo);
    }

    return 0;
}

// Implementações das funções
