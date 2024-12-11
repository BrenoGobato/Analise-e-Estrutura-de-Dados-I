#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o array com valores aleatórios
void fillArrayWithRandom(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range + 1;
    }
}

// Função para particionar o array (usada no Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Função recursiva para o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para medir o tempo de execução do Quick Sort
void measureExecutionTime(int arr[], int size) {
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução do QuickSort para %d elementos: %.6f segundos\n", size, time_spent);
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
