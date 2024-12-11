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

// Função para mesclar dois subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mescla os arrays temporários de volta no array original
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

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para realizar o Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena as metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
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

    // Aplica o Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Array após a ordenação:\n");
    printArray(arr, n);

    return 0;
}
