// ---Instruções da atividade---
// 1. Apresente um programa na linguagem C que execute as seguintes rotinas
// a. Crie um vetor de inteiros de até 20 posições e inclua (via digitação) os valores para cada uma delas.
// b. Apresente na tela: o maior elemento do vetor (e sua posição), o menor elemento do vetor (e sua posição), 
//    a soma de todos os elementos do vetor e a média deles
// c. Elabore uma rotina que entre com um inteiro (variável x) como parâmetro. Indique quantas vezes o valor 
//    dessa variável x aparece entre os elementos do vetor e em quais posições

#include <stdio.h>

int receberValoresNaArray(int *array, int tamanhoMaximo)
{
  int i = 0;

  // Loop para receber os números
  while (i < tamanhoMaximo)
  {
    int numeroDigitado;

    scanf("%d", &numeroDigitado);

    array[i] = numeroDigitado;
    i++;
  }

  return i;
}

int VerificarMaiorMenorSomaMedia(int array[], int tamanho)
{
  // Definindo o indice como 0, ou seja o primeiro elemento da array
  int indiceMaiorElemento = 0, indiceMenorElemento = 0;
  int soma = 0;
  float media;

  for (int j = 0; j < tamanho; j++)
  {
    // Se o item atual da array for maior do que
    // o maior item anterior, então atribua como o maior
    if (array[j] > array[indiceMaiorElemento])
    {
      indiceMaiorElemento = j;
    }

    // Se o item atual da array for menor do que
    // o menor item anterior, então atribua como o menor
    if (array[j] < array[indiceMenorElemento])
    {
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

int VerificarRepeticoes(int array[], int tamanho, int x)
{
  int quantidadeDeRepeticoes = 0;
  // Array para armazenar as posições das repetições
  int indiceDasRepeticoes[tamanho];
  int j = 0;

  // Loop para verificar quantas vezes o número x aparece na array
  for (int i = 0; i < tamanho; i++)
  {
    if (array[i] == x)
    {
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
  for (int k = 0; k < quantidadeDeRepeticoes; k++)
  {
    printf("%d ", indiceDasRepeticoes[k]);
  }

  return 0;
}

int main(void)
{
  int tamanhoMaximo = 20;
  int array[tamanhoMaximo];
  int tamanhoDaArray;
  int numeroDigitado;

  printf("Digite %d números inteiros:\n", tamanhoMaximo);

  tamanhoDaArray = receberValoresNaArray(array, tamanhoMaximo);

  VerificarMaiorMenorSomaMedia(array, tamanhoDaArray);

  printf("\nDigite um número para verificar repetições na array\n");

  scanf("%d", &numeroDigitado);

  VerificarRepeticoes(array, tamanhoDaArray, numeroDigitado);

  return 0;
}