#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);
void trocar(int *xp, int *yp);
void imprimirVetor(int arr[], int size);

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Vetor gerado: \n");
    imprimirVetor(arr, n);

    selectionSort(arr, n);

    printf("\nVetor ordenado: \n");
    imprimirVetor(arr, n);

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        trocar(&arr[min_idx], &arr[i]);
    }
}

void trocar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void imprimirVetor(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
