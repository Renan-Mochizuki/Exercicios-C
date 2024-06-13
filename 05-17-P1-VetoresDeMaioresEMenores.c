// ---Instruções da atividade---
// Apresente um algoritmo (português estruturado) ou uma função em C que crie 2 vetores de inteiros de tamanho de 10 elementos e que peça para que sejam inseridos valores em cada um deles. Depois disso, crie um terceiro vetor que contenha os menores valores para cada índice desses vetores e um quarto vetor que contenha os maiores valores para cada índice.

#include <stdio.h>

void PreencherVetorMaiorMenor(int vetor1[], int vetor2[], int *vetorMaior, int *vetorMenor)
{
  for (int i = 0; i < 10; i++)
  {
    // Analisa qual valor é o maior e atribui nos vetores de maior e menor
    if (vetor1[i] > vetor2[i])
    {
      vetorMaior[i] = vetor1[i];
      vetorMenor[i] = vetor2[i];
    }
    else
    {
      vetorMaior[i] = vetor2[i];
      vetorMenor[i] = vetor1[i];
    }
  }
}

int main(void)
{
  int vetor1[10], vetor2[10];
  int vetorMaior[10], vetorMenor[10];

  printf("Digite 10 valores para o vetor1:\n");

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &vetor1[i]);
  }

  printf("Digite 10 valores para o vetor2:\n");

  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &vetor2[i]);
  }

  PreencherVetorMaiorMenor(vetor1, vetor2, vetorMaior, vetorMenor);

  printf("Os maiores valores de cada posição são:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d, ", vetorMaior[i]);
  }

  printf("\nOs menores valores de cada posição são:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d, ", vetorMenor[i]);
  }

  return 0;
}