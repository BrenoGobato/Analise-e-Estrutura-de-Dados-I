#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    } else
        printf("Erro ao alocar memória!\n");
}

void inserir_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        // Verifica se é o primeiro nó
        if (*lista == NULL) {
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else
        printf("Erro ao alocar memória!\n");
}

void inserir_meio(No **lista, int num, int antes) {
    No *aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;

        if (*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->proximo && aux->valor != antes) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else
        printf("Erro ao alocar memória!\n");
}

void imprimir_fila(No *lista) {
    printf("\n\tLista: ");
    while (lista) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

int main() {
    int opcao, valor, anterior;
    No *lista = NULL;

    do {
        printf("\n0 - Sair \n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Imprimir fila\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e um valor de referência: ");
            scanf("%d %d", &valor, &anterior);
            inserir_meio(&lista, valor, anterior);
            break;
        case 4:
            imprimir_fila(lista);
            break;
        default:
            if (opcao != 0)
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
