#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o array com valores aleatórios
void fillArrayWithRandom(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + rand() % range; // Gera números aleatórios entre 1 e range
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para realizar o Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i]; // Elemento a ser inserido na posição correta
        int j = i - 1;

        // Move os elementos maiores que `key` para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insere `key` na posição correta
    }
}

int main() {
    int n, range;

    // Define a semente para números aleatórios
    srand((unsigned) time(NULL));

    // Solicita o tamanho do array e o intervalo dos números
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    printf("Digite o intervalo máximo dos valores aleatórios: ");
    scanf("%d", &range);

    if (range <= 0) {
        printf("O intervalo máximo deve ser maior que 0.\n");
        return 1;
    }

    int arr[n];

    // Preenche o array com valores aleatórios
    fillArrayWithRandom(arr, n, range);

    printf("Array antes da ordenação:\n");
    printArray(arr, n);

    // Aplica o Insertion Sort
    insertionSort(arr, n);

    printf("Array após a ordenação:\n");
    printArray(arr, n);

    return 0;
}
