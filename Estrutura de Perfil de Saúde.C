#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[80];
    char sexo;
    Data nascimento;
    float altura;
    float peso;
} PerfilSaude;

void calcularIdade(PerfilSaude* perfil);
float calcularIMC(PerfilSaude* perfil);
int calcularFrequenciaMaxima(PerfilSaude* perfil);
void calcularFrequenciaIdeal(PerfilSaude* perfil, int* freqMin, int* freqMax);
void exibirTabelaIMC();
void exibirPerfil(PerfilSaude* perfil);
void exibirMenu();
void calcularExpectativaVida(PerfilSaude* perfil);

int main() {
    PerfilSaude perfil;
    int opcao;

    printf("Digite o nome completo: ");
    scanf(" %[^\n]s", perfil.nome);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &perfil.sexo);
    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &perfil.nascimento.dia, &perfil.nascimento.mes, &perfil.nascimento.ano);
    printf("Digite a altura (em metros): ");
    scanf("%f", &perfil.altura);
    printf("Digite o peso (em kg): ");
    scanf("%f", &perfil.peso);

    exibirPerfil(&perfil);
    calcularIdade(&perfil);
    printf("IMC: %.2f\n", calcularIMC(&perfil));
    int freqMax = calcularFrequenciaMaxima(&perfil);
    printf("Frequência cardíaca máxima: %d bpm\n", freqMax);
    int freqMin, freqMaxIdeal;
    calcularFrequenciaIdeal(&perfil, &freqMin, &freqMaxIdeal);
    printf("Frequência cardíaca ideal: %d - %d bpm\n", freqMin, freqMaxIdeal);
    exibirTabelaIMC();
    calcularExpectativaVida(&perfil);

    return 0;
}

// Implementações das funções
