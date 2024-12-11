#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos no array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição que organiza o array em torno do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;       // Índice para elementos menores que o pivô

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento atual for menor que o pivô
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return i + 1;                  // Retorna o índice do pivô
}

// Função recursiva para ordenar o array usando Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice do pivô

        // Ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para preencher o array com valores aleatórios
void fillArrayWithRandom(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range; // Gera números aleatórios entre 0 e range-1
    }
}

int main() {
    int n, range;

    // Define a semente para números aleatórios
    srand(time(NULL));

    // Solicita o tamanho do array e o intervalo dos números
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    printf("Digite o intervalo máximo dos valores aleatórios: ");
    scanf("%d", &range);

    int arr[n];

    // Preenche o array com valores aleatórios
    fillArrayWithRandom(arr, n, range);

    printf("Array antes da ordenação:\n");
    printArray(arr, n);

    // Aplica o Quicksort
    quickSort(arr, 0, n - 1);

    printf("Array após a ordenação:\n");
    printArray(arr, n);

    return 0;
}
