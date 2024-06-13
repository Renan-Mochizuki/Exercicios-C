// ---Instruções da atividade---
// 4. Apresente um programa similar ao do exercício 3 mas dessa vez podem haver repetições de elementos
// no vetor 1. Nesse caso, apenas um dos elementos do vetor 1 deve ser considerado para a análise

#include <stdio.h>

int VerificarSeArrayPossuiUmNumero(int array[], int tamanho, int num) {
  for (int i = 0; i < tamanho; i++) {
    if (array[i] == num) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  int tamanho = 20;
  int vetor1[tamanho], vetor2[tamanho];
  // Array que armazena os indices dos elementos do vetor1
  // repetidos no vetor 2
  int elementosRepetidos[tamanho * tamanho];
  int k = 0;

  printf("Insira %d valores no vetor 1\n", tamanho);

  // Loop para receber os valores do vetor 1
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &vetor1[i]);
  }

  printf("Insira %d valores no vetor 2\n", tamanho);

  // Loop para receber os valores do vetor 2
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &vetor2[i]);
  }

  // Loop para percorrer todos os itens do vetor 1
  for (int i = 0; i < tamanho; i++) {
    // Loop para percorrer todos os itens do vetor 2
    for (int j = 0; j < tamanho; j++) {
      int numeroJaInserido =
          VerificarSeArrayPossuiUmNumero(elementosRepetidos, k, vetor1[i]);
      // Se o item do vetor 1 for igual a qualquer um no vetor 2
      // e o número ainda não tiver sido inserido
      // armazene este item
      if (vetor1[i] == vetor2[j] && 
        numeroJaInserido == 0) 
      {
        elementosRepetidos[k] = vetor1[i];
        k++;
      }
    }
  }

  if (k > 0) {
    printf("Os elementos repetidos do vetor 1 no vetor 2 são:\n");

    // Loop para imprimir todos os elementos repetidos
    for (int i = 0; i < k; i++) {
      printf("%d ", elementosRepetidos[i]);
    }
  } else {
    printf("Não há elementos repetidos do vetor 1 no vetor 2\n");
  }

  return 0;
}