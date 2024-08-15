// ---Instruções da atividade---
// Dado um ponteiro (p1) de uma lista ligada, retorne um ponteiro (p2) de uma
// outra lista ligada que contenha os elementos pares dessa lista

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *proximo;
} itemNo;

void ImprimirLista(itemNo **primeiroItem) {
    itemNo *itemAtual = *primeiroItem;

    // Percorre a lista até o NULL
    while (itemAtual != NULL) {
        printf("%d, ", itemAtual->valor);
        itemAtual = itemAtual->proximo;
    }
    printf("\n");
}

void InserirFimLista(itemNo **primeiroItem, int valor) {
    // Criando o novo nó
    itemNo *novoItem = malloc(sizeof(itemNo));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    // Se a lista estiver vazia, defina o primeiro item como o novo
    if (*primeiroItem == NULL) {
        *primeiroItem = novoItem;
        return;
    }

    itemNo *itemAtual = *primeiroItem;

    // Loop que percorre até o último item
    while (itemAtual->proximo != NULL) {
        itemAtual = itemAtual->proximo;
    }

    // Atribuindo o novoItem no final da lista
    itemAtual->proximo = novoItem;
}

itemNo *RetornarListaPares(itemNo **p1) {
    itemNo *p2 = NULL;
    itemNo *itemAtual = *p1;

    // Loop que percorre até o NULL
    while (itemAtual != NULL) {
        int valor = itemAtual->valor;
        // Se o valor for par, insira no final da lista p2
        if (valor % 2 == 0) {
            InserirFimLista(&p2, valor);
        }
        itemAtual = itemAtual->proximo;
    }

    // Retornando o ponteiro da lista p2
    return p2;
};

void LimparLista(itemNo **primeiroItem) {
    itemNo *itemAtual = *primeiroItem;
    itemNo *proximoItem = NULL;

    // Percorre até o NULL
    while (itemAtual != NULL) {
        // Armazena o próximo item
        proximoItem = itemAtual->proximo;
        free(itemAtual);
        itemAtual = proximoItem;
    }

    // Define o primeiro item como NULL
    *primeiroItem = NULL;
}

int main(void) {
    itemNo *head = NULL;
    itemNo *p1 = NULL;
    itemNo *p2 = NULL;

    // Criando uma lista arbitrária para p1
    InserirFimLista(&p1, 1);
    InserirFimLista(&p1, 2);
    InserirFimLista(&p1, 3);
    InserirFimLista(&p1, 4);
    InserirFimLista(&p1, 5);
    InserirFimLista(&p1, 6);

    p2 = RetornarListaPares(&p1);

    ImprimirLista(&p2);

    LimparLista(&p1);
    LimparLista(&p2);

    return 0;
}