// ---Instruções da atividade---
// 5. Em uma competição de ginástica, a nota é determinada por um painel de seis juízes. Cada um deles 
// atribui uma nota entre zero e dez para o desempenho do atleta. Para calcular a nota final, a nota
// mais alta e a nota mais baixa são descartadas e é calculada a média das quatro restantes. 
// Apresente um algoritmo (português estruturado) ou parte de um programa em C que receba por parâmetro 
// essas 6 notas entre zero e dez e calcule a média após o descarte da maior e da menor 

#include <stdio.h>

float CalcularMedia(int notas[]) {
  float media;
  // Atribuindo o primeiro valor na variável maior, menor e soma
  int soma = notas[0];
  int maior = notas[0];
  int menor = notas[0];

  // i=1, pois o primeiro valor já foi atribuído
  for (int i = 1; i < 6; i++) {
    if (notas[i] > maior) {
      maior = notas[i];
    }
    if (notas[i] < menor) {
      menor = notas[i];
    }
    soma = soma + notas[i];
  }

  // Calculando a média descartando a maior e menor notas
  media = (float)(soma - maior - menor)/4;

  return media;
}

int main(void) {
  int notas[6];
  float media;

  printf("Insira as 6 notas dos juízes\n");

  for (int i = 0; i < 6; i++) {
    scanf("%d", &notas[i]);
  }

  media = CalcularMedia(notas);

  printf("A média dos juízes é: %.2f\n", media);
  
  return 0;
}