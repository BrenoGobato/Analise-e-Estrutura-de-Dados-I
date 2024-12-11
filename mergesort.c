#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o array com valores aleatórios
void fillArrayWithRandom(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range + 1;
    }
}

// Função para mesclar dois subarrays (usada no Merge Sort)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para o Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Função para medir o tempo de execução do Merge Sort
void measureExecutionTime(int arr[], int size) {
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução do MergeSort para %d elementos: %.6f segundos\n", size, time_spent);
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
