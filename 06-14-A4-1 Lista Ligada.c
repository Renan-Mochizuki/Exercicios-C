// ---Instruções da atividade---
// Implementar e "rodar" um programa em C que:
// a) Crie uma lista ligada (simples), sendo que um nó contenha um INT e um ponteiro para o próximo nó; 
//    (ao criar a lista, o ponteiro inicial deve apontar para NULL)
// Elabore rotinas para
// b) Inserir um elemento no início da lista
// c) Inserir um elemento no fim da lista
// d) Excluir um elemento no início da lista
// e) Excluir um elemento do fim da lista
// f) Procure por um elemento (valor do inteiro) na lista - retorne 1 se achou e 0 caso contrário

#include <stdio.h>
#include <stdlib.h>

// Declarando com o nome itemNo, um nó que possui
// valor e um ponteiro para o próximo item
typedef struct node {
  int valor;
  struct node *proximo;
} itemNo;

// Função que imprime a lista até o NULL
void ImprimirLista(itemNo *primeiroItem) {
  itemNo *itemAtual = primeiroItem;

  // Loop que percorre a lista até encontrar o NULL
  while (itemAtual != NULL) {
    printf("%d ", itemAtual->valor);
    // Altere o itemAtual para o próximo item
    itemAtual = itemAtual->proximo;
  }
  printf("\n");
}

// Função que criará um novo nó e definará ele como o primeiro
// **primeiroItem pega o ponteiro do primeiroItem e não seu valor
void InserirInicioLista(itemNo **primeiroItem, int valor) {
  // Criando um novo nó que armazenará o valor
  itemNo *novoItem = malloc(sizeof(itemNo));
  novoItem->valor = valor;

  // Definindo o próximo do novoItem como o primeiroItem atual
  novoItem->proximo = *primeiroItem;

  // Alterando o primeiroItem para o novoItem
  *primeiroItem = novoItem;
}

// Função que achará o último nó da lista e substituirá seu
// próximo como sendo um novo nó com o valor
void InserirFimLista(itemNo **primeiroItem, int valor) {
  // Se a lista estiver vazia
  if (*primeiroItem == NULL) {
    // Declara um novo item e atribue os valores
    itemNo *itemNovo = malloc(sizeof(itemNo));
    itemNovo->valor = valor;
    itemNovo->proximo = NULL;
    *primeiroItem = itemNovo;
  }
  // Se a lista não estiver vazia
  else {
    // Declarando o itemAtual como sendo o primeiroItem
    itemNo *itemAtual = *primeiroItem;

    // Loop que percorre toda a lista até seu penúltimo item
    while (itemAtual->proximo != NULL) {
      itemAtual = itemAtual->proximo;
    }

    // Alterando o valor de proximo alocando memória para um novo nó
    itemAtual->proximo = malloc(sizeof(itemNo));
    itemAtual->proximo->valor = valor;

    // Definindo o próximo do item novo como NULL pois é o último
    itemAtual->proximo->proximo = NULL;
  }
}

// Função que recebe o ponteiro do primeiroItem
int RemoverInicioLista(itemNo **primeiroItem) {
  // Se a lista estiver vazia, a função faz nada
  if (*primeiroItem == NULL)
    return 0;

  // Guardando o segundoItem da lista
  // () necessário para que não seja interpretado como *(primeiroItem->proximo)
  itemNo *segundoItem = (*primeiroItem)->proximo;

  // Removendo o primeiroItem da lista
  free(primeiroItem);

  // Definindo o primeiroItem agora como o segundoItem
  *primeiroItem = segundoItem;

  // Retorne 1 se a função foi executada com sucesso
  return 1;
}

// Função que remove o último item e define o próximo do penúltimo como NULL
int RemoverFimLista(itemNo **primeiroItem) {
  // Se a lista estiver vazia, a função faz nada
  if (*primeiroItem == NULL)
    return 0;

  // Se houver apenas um item na lista
  if ((*primeiroItem)->proximo == NULL) {
    // Remova ele
    free(*primeiroItem);
    *primeiroItem = NULL;
  }
  // Se houver mais de um item na lista
  else {
    itemNo *itemAtual = *primeiroItem;

    // Guardando o penúltimoItem da lista no itemAtual
    while (itemAtual->proximo->proximo != NULL) {
      itemAtual = itemAtual->proximo;
    }

    // Removendo o últimoItem da lista
    itemNo *ultimoItem = itemAtual->proximo;
    free(ultimoItem);
    itemAtual->proximo = NULL;
  }

  // Retorne 1 se a função foi executada com sucesso
  return 1;
}

// Função que percorre toda a lista verificando o valor
int VerificarExistenciaItem(itemNo *primeiroItem, int valor) {
  itemNo *itemAtual = primeiroItem;
  // Loop que percorre toda a lista
  while (itemAtual != NULL) {
    // Se o valor for encontrado, retorne 1
    if (itemAtual->valor == valor) {
      return 1;
    }
    // Altere o itemAtual para o próximo item
    itemAtual = itemAtual->proximo;
  }
  // Se não for encontrado retorne 0
  return 0;
}

int main(void) {
  int numeroDigitado;
  int loopAtivado = 1;
  // Alocando memória para o primeiro item da lista
  itemNo *primeiroItem = NULL;
  // Definindo o valor do primeiro item como 0 e o próximo como NULL

  // Loop para ficar perguntando até o 0 ser escolhido
  while (loopAtivado) {
    printf("Qual ação deseja realizar?\n");
    printf("1 - Inserir valor no início da lista\n");
    printf("2 - Inserir valor no fim da lista\n");
    printf("3 - Remover o primeiro item da lista\n");
    printf("4 - Remover o último item da lista\n");
    printf("5 - Verificar existência de item\n");
    printf("0 - Sair\n");
    scanf("%d", &numeroDigitado);
    switch (numeroDigitado) {
    case 0:
      loopAtivado = 0;
      break;

    case 1:
      printf("Digite o valor que deseja inserir no início da lista\n");
      scanf("%d", &numeroDigitado);
      InserirInicioLista(&primeiroItem, numeroDigitado);
      break;

    case 2:
      printf("Digite o valor que deseja inserir no fim da lista\n");
      scanf("%d", &numeroDigitado);
      InserirFimLista(&primeiroItem, numeroDigitado);
      break;

    case 3:
      if (RemoverInicioLista(&primeiroItem)) {
        printf("O primeiro item foi removido da lista\n");
      } else {
        printf("Não haviam itens para serem removidos\n");
      }
      break;

    case 4:
      if (RemoverFimLista(&primeiroItem)) {
        printf("O último item foi removido da lista\n");
      } else {
        printf("Não haviam itens para serem removidos\n");
      }
      break;

    case 5:
      printf("Digite o valor que deseja verificar\n");
      scanf("%d", &numeroDigitado);
      if (VerificarExistenciaItem(primeiroItem, numeroDigitado)) {
        printf("O valor %d existe na lista\n", numeroDigitado);
      } else {
        printf("O valor não existe na lista\n");
      }
      break;

    default:
      break;
    }

    if (primeiroItem == NULL) {
      printf("\n- A lista está vazia\n\n");
    } else {
      printf("\n- A lista agora tem os valores:\n");
      ImprimirLista(primeiroItem);
      printf("\n");
    }
  }

  // Declarando itemAtual sendo o primeiroItem
  itemNo *itemAtual = primeiroItem;
  // Loop que percorre toda a lista
  while (itemAtual != NULL) {
    // Guardando o itemAtual no auxiliar para limpar
    itemNo *auxiliar = itemAtual;
    itemAtual = itemAtual->proximo;
    // Liberar memória do itemAtual
    free(auxiliar);
  }

  return 0;
}