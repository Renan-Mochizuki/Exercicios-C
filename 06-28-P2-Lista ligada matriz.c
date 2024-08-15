// ---Instruções da atividade---
// Dada uma matriz de inteiros esparsa de no máximo 10000 por 10000, sendo que a
// matriz pode conter varios elementos como o 0, retorne o ponteiro de uma lista
// ligada que tenha nós com dados info (valor), linha (linha que aquele valor
// está na matriz) e coluna (coluna que aquele valor está na matriz), que
// contenha todos os elementos da matriz diferentes de 0.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nLinhas 10
#define nColunas 10

typedef struct node {
    int valor;
    int linha;
    int coluna;
    struct node *proximo;
} itemNo;

void InserirNumerosAleatorios(int matriz[nLinhas][nColunas]) {
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            // Inserindo valores aleatórios de 0 a 100 na matriz
            matriz[i][j] = rand() % 101;
        }
    }
}

void ImprimirMatriz(int matriz[nLinhas][nColunas]) {
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ImprimirLista(itemNo **primeiroItem) {
    itemNo *itemAtual = *primeiroItem;

    // Percorre a lista até o NULL
    while (itemAtual != NULL) {
        printf("%d, ", itemAtual->valor);
        printf("pos: [%d][%d]\n", itemAtual->linha,itemAtual->coluna);
        itemAtual = itemAtual->proximo;
    }
}

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

void InserirFimLista(itemNo **primeiroItem, int valor, int linha, int coluna) {
    // Criando o novo nó
    itemNo *novoItem = malloc(sizeof(itemNo));
    novoItem->valor = valor;
    novoItem->linha = linha;
    novoItem->coluna = coluna;
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

itemNo *RetornarListaMatriz(int matriz[nLinhas][nColunas]) {
    itemNo *head = NULL;

    // Loop para percorrer toda a matriz
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            int valor = matriz[i][j];
            if (valor != 0) {
                InserirFimLista(&head, valor, i, j);
            }
        }
    }
    return head;
}

int main(void) {
    int matriz[nLinhas][nColunas];
    itemNo *head = NULL;

    // Inicialização necessária para gerar números aleatórios
    srand(time(NULL));


    InserirNumerosAleatorios(matriz);

    printf("Matriz:\n");
    ImprimirMatriz(matriz);

    head = RetornarListaMatriz(matriz);

    printf("\nLista Ligada:\n");
    ImprimirLista(&head);

    LimparLista(&head);

    return 0;
}