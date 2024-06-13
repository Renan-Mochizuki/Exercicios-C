// ---Instruções da atividade---
// 2. Apresente um programa similar ao do exercício 1 só que dessa vez os elementos do vetor são 
// apenas inteiros >= 0. Caso seja inserido um valor negativo, deve-se parar de inserir elementos no vetor. 
// (cuidado para não inserir o valor negativo). Os itens a, b e c do exercício 1 também devem ser realizados

#include <stdio.h>

int receberValoresNaArray(int *array, int tamanhoMaximo) {
  int i = 0;

  // Loop para receber os números
  while (i < tamanhoMaximo) {
    int numeroDigitado;

    scanf("%d", &numeroDigitado);

    // Caso o número digitado seja negativo, pare o loop
    if (numeroDigitado < 0) {
      break;
    }

    array[i] = numeroDigitado;
    i++;
  }

  return i;
}

int VerificarMaiorMenorSomaMedia(int array[], int tamanho) {
  // Definindo o indice como 0, ou seja o primeiro elemento da array
  int indiceMaiorElemento = 0, indiceMenorElemento = 0;
  int soma = 0;
  float media;

  for (int j = 0; j < tamanho; j++) {
    // Se o item atual da array for maior do que
    // o maior item anterior, então atribua como o maior
    if (array[j] > array[indiceMaiorElemento]) {
      indiceMaiorElemento = j;
    }

    // Se o item atual da array for menor do que
    // o menor item anterior, então atribua como o menor
    if (array[j] < array[indiceMenorElemento]) {
      indiceMenorElemento = j;
    }

    soma = soma + array[j];
  }

  media = (float)soma / tamanho;

  printf("O maior elemento é %d e sua posição no vetor é %d\n",
         array[indiceMaiorElemento], indiceMaiorElemento);

  printf("O menor elemento é %d e sua posição no vetor é %d\n",
         array[indiceMenorElemento], indiceMenorElemento);

  printf("A soma do vetor é %d e a média %f\n", soma, media);

  return 0;
}

int VerificarRepeticoes(int array[], int tamanho, int x) {
  int quantidadeDeRepeticoes = 0;
  // Array para armazenar as posições das repetições
  int indiceDasRepeticoes[tamanho];
  int j = 0;

  // Loop para verificar quantas vezes o número x aparece na array
  for (int i = 0; i < tamanho; i++) {
    if (array[i] == x) {
      // Armazenando as posições numa array
      indiceDasRepeticoes[j] = i;
      j++;
      // Contando a quantidade
      quantidadeDeRepeticoes++;
    }
  }

  printf("O número %d aparece %d vezes\n", x, quantidadeDeRepeticoes);

  printf("Nas posições da array: ");

  // Loop para imprimir as posições armazenadas na array
  for (int k = 0; k < quantidadeDeRepeticoes; k++) {
    printf("%d ", indiceDasRepeticoes[k]);
  }

  return 0;
}

int main(void) {
  int tamanhoMaximo = 20;
  int array[tamanhoMaximo];
  int tamanhoDaArray;
  int numeroDigitado;

  printf("Digite %d números inteiros maiores ou iguais a 0:\n", tamanhoMaximo);
  printf("Para parar, digite um número negativo\n");

  tamanhoDaArray = receberValoresNaArray(array, tamanhoMaximo);

  VerificarMaiorMenorSomaMedia(array, tamanhoDaArray);

  printf("\nDigite um número para verificar repetições na array\n");

  scanf("%d", &numeroDigitado);

  VerificarRepeticoes(array, tamanhoDaArray, numeroDigitado);

  return 0;
}