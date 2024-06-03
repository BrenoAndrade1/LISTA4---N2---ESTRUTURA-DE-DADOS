#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[100];
    struct Paciente* prox;
} Paciente;

typedef struct {
    Paciente* frente;
    Paciente* tras;
} FilaAtendimento;

void inicializarFila(FilaAtendimento* fila);
void adicionarPaciente(FilaAtendimento* fila, char* nome);
Paciente* proximoPaciente(FilaAtendimento* fila);
int quantidadePacientes(FilaAtendimento* fila);
void exibirMenu();

int main() {
    FilaAtendimento fila;
    inicializarFila(&fila);
    int opcao;
    char nome[100];

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]s", nome);
                adicionarPaciente(&fila, nome);
                break;
            case 2:
                Paciente* paciente = proximoPaciente(&fila);
                if (paciente != NULL) {
                    printf("Próximo paciente: %s\n", paciente->nome);
                    free(paciente);
                } else {
                    printf("Não há pacientes na fila.\n");
                }
                break;
            case 3:
                printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Implementações das funções
