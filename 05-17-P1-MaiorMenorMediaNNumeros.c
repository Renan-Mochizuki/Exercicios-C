// ---Instruções da atividade---
// Apresente um algoritmo (português estruturado) ou uma função em C que peça para ser digitado um
// número inteiro N. Depois disso, devem ser inseridos N números reais e ao final que sejam 
// apresentados o maior número digitado, o menor número e a média dos números digitados.

#include <stdio.h>

void ImprimirMaiorMenorMedia(int vetor[], int n) {
  float media;
  // Armazenando o primeiro valor na variável maior e menor e soma
  int maior = vetor[0];
  int menor = vetor[0];
  int soma = vetor[0];

  // Começando em i=1 porque o 0 ja foi definido
  for (int i = 1; i < n; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
    soma = soma + vetor[i];
  }

  media = (float)soma / n;

  printf("O maior valor dentre os %d valores é %d\n", n, maior);
  printf("O menor valor é %d\n", menor);
  printf("A média é %.2f\n", media);
}

int main(void) {
  int n;

  printf("Digite a quantidade de números a serem inseridos:\n");
  scanf("%d", &n);

  int vetor[n];

  printf("Digite %d números\n", n);

  // Loop para receber os valores em uma array
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }

  ImprimirMaiorMenorMedia(vetor, n);

  return 0;
}