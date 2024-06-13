// ---Instruções da atividade---
// Elabore (implemente e rode!) um programa em C que:
// - cria um vetor de no máximo 30 posições
// - peça que sejam digitados números (máximo 30) que sejam inseridos nesse vetor
// - ordene esse vetor
// - peça que se indique se quer que seja inserido um novo número nesse vetor
// - caso não se tenham ainda 30 números nesse vetor, inserir esse novo número ao final do vetor e ordená-lo
// - repetir os 2 passos acima até que se tenha 30 números no vetor
// - fazer uma busca binária por um número nesse vetor ordenado
// - informar qual a posição no vetor que esse número se encontra ou imprimir que não achou o número, se for o caso

#include <stdio.h>
#include <string.h>

// Ordenar vetor pelo Bubble Sort
int OrdenarVetor(int vetor[], int tamanho) {
  int i = 0;
  int trocou = 0;
  do {
    trocou = 0;
    int criterioDoLoop = tamanho - 1 - i;
    for (int j = 0; j < criterioDoLoop; j++) {
      if (vetor[j] > vetor[j + 1]) {
        int auxiliar = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = auxiliar;
        trocou = 1;
      }
    }
    i++;
  } while (trocou == 1);

  return 0;
}

// Função para busca binária
int EncontrarValor(int *vetor, int valor, int inicio, int fim) {

  // Se o inicio for maior que o fim, então o vetor não possui o valor
  if (inicio > fim) {
    return -1;
  }

  // Pegando a metade do intervalo passado
  int meio = (inicio + fim) / 2;

  // Se o item do meio for maior que o valor, então o valor está na metade
  // inferior, logo, mude o intervalo
  if (vetor[meio] > valor) {
    return EncontrarValor(vetor, valor, inicio, meio - 1);
  }
  if (vetor[meio] < valor) {
    return EncontrarValor(vetor, valor, meio + 1, fim);
  }
  // Se o item do meio for o valor, então retorne esse indice
  return meio;
}

int main(void) {
  int vetor[30];
  int i, numeroDigitado;
  char textoDigitado[2];

  printf("Digite no máximo 30 inteiros:\n");
  printf("Digite um número negativo para parar.\n");

  // Loop que recebe os valores e para se for digitado um negativo
  for (i = 0; i < 30; i++) {
    scanf("%d", &numeroDigitado);
    if (numeroDigitado < 0) {
      break;
    }
    vetor[i] = numeroDigitado;
  }

  OrdenarVetor(vetor, i);

  printf("O vetor ordenado é:\n");

  // Loop para imprimir
  for (int j = 0; j < i; j++) {
    printf("%d, ", vetor[j]);
  }

  // Se ainda não houver 30 números
  if (i < 30) {
    // Loop para continuar perguntando se deseja inserir
    while (i < 30) {
      printf("\n\nDeseja inserir mais números? (S/N)\n");
      scanf("%s", textoDigitado);
      // Se o texto digitado for "S"
      if (strncmp(textoDigitado, "S", 1) == 0 ||
          strncmp(textoDigitado, "s", 1) == 0) {
        printf("Digite um número negativo para parar.\n");
        // Loop que para quando for inserido no total 30 números
        while (i < 30) {
          scanf("%d", &numeroDigitado);
          // Se o número digitado for negativo, para o loop
          if (numeroDigitado < 0) {
            // Ordena o vetor novamente
            OrdenarVetor(vetor, i);

            printf("O vetor ordenado é:\n");

            // Loop para imprimir
            for (int j = 0; j < i; j++) {
              printf("%d, ", vetor[j]);
            }

            break;
          }
          vetor[i] = numeroDigitado;
          i++;
        }
      } else {
        printf("\nVocê é obrigado a dizer 'S' até ter 30 números\n");
        printf("Faltam %d números para serem inseridos\n", 30 - i);
      }
    }
  }
  
  // Ordena o vetor novamente
  OrdenarVetor(vetor, i);

  printf("O vetor ordenado é:\n");

  // Loop para imprimir
  for (int j = 0; j < i; j++) {
    printf("%d, ", vetor[j]);
  }
  
  numeroDigitado = -1;
  // Loop para rejeitar números negativos
  while (numeroDigitado < 0) {
    printf("\n\nAgora insira um número positivo para que seja buscado no vetor:\n");
    scanf("%d", &numeroDigitado);
  }

  // Busca binária
  int indice = EncontrarValor(vetor, numeroDigitado, 0, 30);

  // Se a busca binária não encontrar o número
  if (indice == -1) {
    printf("O número não foi encontrado no vetor\n");
  } else {
    printf("O número foi encontrado no índice %d\n", indice);
  };

  while (1) {
    printf("\n\nDeseja procurar outros números? (S/N)\n");
    scanf("%s", textoDigitado);
    // Se o texto digitado for "S"
    if (strncmp(textoDigitado, "S", 1) == 0 ||
        strncmp(textoDigitado, "s", 1) == 0) {
      numeroDigitado = -1;
      // Loop para rejeitar números negativos
      while (numeroDigitado < 0) {
        printf("\n\nInsira um número positivo para buscar no vetor:\n");
        scanf("%d", &numeroDigitado);
      }

      // Busca binária
      int indice = EncontrarValor(vetor, numeroDigitado, 0, 30);

      // Se a busca binária não encontrar o número
      if (indice == -1) {
        printf("O número não foi encontrado no vetor\n");
      } else {
        printf("O número foi encontrado no índice %d\n", indice);
      };
    } else {
      break;
    }
  }

  return 0;
}