// ---Instruções da atividade---
// A atividade de hoje é implementar uma função que retorne um ponteiro para uma lista ligada 
// que contenha os elementos de uma Matriz de 5 x 5 elementos
// Exemplo:
// Sendo M   01       02       03      04     05
//           06       07       08      09     10
//           11       12       13      14     15
//           16       17       18      19     20
//           21       22       23      24     25
// A lista a ser retornada será
// (primeiro nó em que head aponta para será o nó cujo campo info vale 01, o segundo 02 e assim por diante
// 01 ->  02  ->  03  ->  04  -> 05  -> 06  -> 07  -> 08  ->  09  -> 10  -> 11  -> 12  -> 13  ->  
// 14  -> 15  -> 16  -> 17  -> 18  -> 19  -> 20  -> 21  -> 22  -> 23  -> 24  -> 25  -> <<NULL>>

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *proximo;
} noLista;

void InserirFimLista(noLista **head, int valor) {
  // Criando novo nó com o valor
  noLista *novoNo = malloc(sizeof(noLista));
  novoNo->valor = valor;
  novoNo->proximo = NULL;

  // se a lista estiver vazia, o novo nó será a head
  if (*head == NULL) {
    *head = novoNo;
    return;
  }

  // Definindo nó atual para interar
  noLista *noAtual = *head;

  // Loop que percorre toda a lista
  while (noAtual->proximo != NULL) {
    noAtual = noAtual->proximo;
  }

  // Inserindo novo nó no final da lista
  noAtual->proximo = novoNo;
}

noLista *CriarMatrizQuadrada(int tamanho) {
  // Criando a head
  noLista *head = NULL;

  // Definindo quantidade de nós
  int quantidadeNos = tamanho * tamanho;
  // Loop que preenche a lista de um a um
  for (int i = 1; i <= quantidadeNos; i++) {
    InserirFimLista(&head, i);
  }

  // Retornando a head
  return head;
}

void ImprimirListaMatriz(noLista **head, int tamanho) {
  noLista *noAtual = *head;
  // Loop para imprimir a matriz
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("%d ", noAtual->valor);
      noAtual = noAtual->proximo;
    }
    printf("\n");
  }
}

int main(void) {
  int tamanho;

  printf("Qual será o tamanho da matriz?\n");
  scanf("%d", &tamanho);

  // Declarando head e recebendo ponteiro da função
  noLista *head = NULL;
  head = CriarMatrizQuadrada(tamanho);

  printf("A matriz é: \n");

  ImprimirListaMatriz(&head, tamanho);

  return 0;
}