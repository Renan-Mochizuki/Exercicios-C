// ---Instruções da atividade---
// Dados ponteiros de duas listas ligadas (p1 e p2), retorne a quantidade de
// elementos repetidos entre as listas (Considerando que as listas não tem
// elementos repetidos nelas mesmas, não é especificado se a lista está ordenada
// ou não)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *proximo;
} itemNo;

void LimparLista(itemNo **primeiroItem)
{
    itemNo *itemAtual = *primeiroItem;
    itemNo *proximoItem = NULL;

    // Percorre até o NULL
    while (itemAtual != NULL)
    {
        // Armazena o próximo item
        proximoItem = itemAtual->proximo;
        free(itemAtual);
        itemAtual = proximoItem;
    }

    // Define o primeiro item como NULL
    *primeiroItem = NULL;
}

void ImprimirLista(itemNo **primeiroItem)
{
    itemNo *itemAtual = *primeiroItem;

    // Percorre a lista até o NULL
    while (itemAtual != NULL)
    {
        printf("%d, ", itemAtual->valor);
        itemAtual = itemAtual->proximo;
    }
}

void InserirFimLista(itemNo **primeiroItem, int valor)
{
    // Criando o novo nó
    itemNo *novoItem = malloc(sizeof(itemNo));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    // Se a lista estiver vazia, defina o primeiro item como o novo
    if (*primeiroItem == NULL)
    {
        *primeiroItem = novoItem;
        return;
    }

    itemNo *itemAtual = *primeiroItem;

    // Loop que percorre até o último item
    while (itemAtual->proximo != NULL)
    {
        itemAtual = itemAtual->proximo;
    }

    // Atribuindo o novoItem no final da lista
    itemAtual->proximo = novoItem;
}

int RetornarQuantidadeRepetidos(itemNo **p1, itemNo **p2, itemNo **pRepetido)
{
    itemNo *itemAtualp1 = *p1;
    itemNo *itemAtualp2 = *p2;
    int quantidade = 0;

    // Loop que percorre a lista p2 para cada item da lista p1
    while (itemAtualp1 != NULL)
    {
        int valorp1 = itemAtualp1->valor;
        while (itemAtualp2 != NULL)
        {
            int valorp2 = itemAtualp2->valor;
            if (valorp1 == valorp2)
            {
                quantidade++;
                InserirFimLista(pRepetido, valorp1);
            }
            itemAtualp2 = itemAtualp2->proximo;
        }
        itemAtualp1 = itemAtualp1->proximo;
        // Reseta o itemAtualp2 para o início da lista p2
        itemAtualp2 = *p2;
    }

    return quantidade;
}

int main(void)
{
    itemNo *p1 = NULL;
    itemNo *p2 = NULL;
    itemNo *pRepetido = NULL;
    int quantidade;

    // Inserindo valores arbitrários na lista p1 e p2
    InserirFimLista(&p1, 1);
    InserirFimLista(&p1, 2);
    InserirFimLista(&p1, 3);
    InserirFimLista(&p1, 6);
    InserirFimLista(&p1, 9);
    InserirFimLista(&p2, 2);
    InserirFimLista(&p2, 6);
    InserirFimLista(&p2, 9);
    InserirFimLista(&p2, 10);

    quantidade = RetornarQuantidadeRepetidos(&p1, &p2, &pRepetido);

    printf("Há %d elementos repetidos entre as listas:\n", quantidade);

    ImprimirLista(&pRepetido);

    LimparLista(&p1);
    LimparLista(&p2);
    LimparLista(&pRepetido);

    return 0;
}