#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o array com valores aleatórios
void fillArrayWithRandom(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range + 1;
    }
}

// Função para realizar o Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para medir o tempo de execução do Insertion Sort
void measureExecutionTime(int arr[], int size) {
    clock_t start = clock();
    insertionSort(arr, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução do InsertionSort para %d elementos: %.6f segundos\n", size, time_spent);
}

int main() {
    srand((unsigned int)time(NULL));

    int n, range = 1000;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O tamanho do array deve ser maior que zero.\n");
        return 1;
    }

    int arr[n];
    fillArrayWithRandom(arr, n, range);
    measureExecutionTime(arr, n);

    return 0;
}
