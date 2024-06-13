// ---Instruções da atividade---
// Apresente um algoritmo (português estruturado) ou uma função em C que leia um número inteiro N que seja maior ou igual a 0 e o mostre na notação binária

#include <stdio.h>

// Passando array com ponteiro
int ConverterParaBinario(int *array, int num)
{
  int i = 0;

  // Loop que pega o resto de cada dividendo que foi dividido por 2 até chegar
  // no 0
  for (int dividendo = num; dividendo != 0; dividendo = dividendo / 2)
  {
    array[i] = dividendo % 2;
    i++;
  }

  // Retornando o tamanho da array
  return i;
}

int main(void)
{
  int arrayBinario[32];
  int numDigitado, tamanho;

  printf("Digite um número inteiro\n");
  scanf("%d", &numDigitado);

  // Inserindo os valores na array e recebendo o tamanho dela
  tamanho = ConverterParaBinario(arrayBinario, numDigitado);

  printf("O número convertido para binário é:\n");

  // Loop para imprimir todos os valores da array ao contrário
  for (int i = tamanho - 1; i >= 0; i--)
  {
    printf("%d", arrayBinario[i]);
  }

  return 0;
}