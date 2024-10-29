#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char Nome[50];
    Data  data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa(){
    Pessoa p;

    printf("Digite nome e data de nascimento (dd mm aaaa) :\n");
    scanf(" %49[^\n]", p.Nome);
    scanf("%d %d %d", &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s \nData: %2d/%2d/%4d\n", p.Nome, p.data.dia, p.data.mes, p.data.ano);
}

//Funcao para a operacao push()
No* empilhar(No *topo){
    No *novo_no = malloc (sizeof(No));

    if(novo_no){
        novo_no->p = ler_pessoa();
        novo_no->proximo = topo;
        return novo_no;
    }else{
        printf("Erro ao alocar memoria!!!\n");
        return NULL;
    }
}

//Funcao para a operacao pop()
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else{
        printf("Pilha vazia");
        return NULL;
    }
}

//Funcao Imprimir()
void imprimir_pilha(No *topo){
    if (!topo) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("--------------- PILHA ---------------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n------------ FIM DA PILHA ------------");
}

int main(){
    No *remover, *topo = NULL;
    int opcao;

    do{
        printf("\n0 - Sair \n1 - Empilhar \n2 - Desempilhar \n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("Elemento removido com sucesso!");
                imprimir_pessoa(remover->p);
            }else
                printf("Sem no a remover\n");
            break;
        case 3:
            imprimir_pilha(topo);
            break;
        default:
            if(opcao != 0)
                printf("Opcao Invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
