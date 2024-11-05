#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir_Fila(No **fila, int num) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->proximo = NULL;
        novo->valor = num;
        if (*fila == NULL) {
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    } else
        printf("\nErro ao alocar memória\n");
}

No *remover_Fila(No **fila) {
    No *remover = NULL;
    if (*fila) {
        remover = *fila;
        *fila = remover->proximo;
    } else
        printf("\nFila vazia\n");
    return remover;
}

void imprimir_Fila(No *fila) {
    printf("\t------------FILA--------------\n\t");
    while (fila) {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t---------FIM DA FILA-----------\n");
}

int main() {
    No *rem, *fila = NULL;
    int opcao, valor;

    do {
        printf("\t 0 - Sair | 1 - Inserir | 2 - Remover | 3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_Fila(&fila, valor);
                break;
            case 2:
                rem = remover_Fila(&fila);
                if (rem) {
                    printf("Removido: %d\n", rem->valor);
                    free(rem);
                }
                break;
            case 3:
                imprimir_Fila(fila);
                break;
            default:
                if (opcao != 0)
                    printf("\n Opcao Invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
