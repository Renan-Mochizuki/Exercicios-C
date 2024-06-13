// ---Instruções da atividade---
// 1. Entrar com N números inteiros e maiores ou iguais a zero e dizer qual foi o maior número entrado, 
// qual o menor, a soma deles e a média. Os critérios de parada são: (a) Pode-se pedir para que se 
// digite o valor de N e que se entre exatamente N números; ou (b)  um dos números digitados seja negativo

#include <stdio.h>

int main(void) {
  int quantidadeDeNumeros = 0;
  int maiorNumeroAtual = 0;
  int menorNumeroAtual = 0;
  int soma = 0;
  int numeroDigitado;
  float media;

  printf("Digite os números\n");
  printf("Para parar digite um número negativo\n");

  while (1) {
    printf("Digite o número %d:\n", quantidadeDeNumeros + 1);
    scanf("%d", &numeroDigitado);

    // Pare o loop caso for digitado um número negativo
    if (numeroDigitado < 0) {
      break;
    }
    
    // Definindo o primeiro número digitado como o maior e o menor
    // Para que a comparação possa ser feita 
    if(quantidadeDeNumeros == 0){
      maiorNumeroAtual = numeroDigitado;
      menorNumeroAtual = numeroDigitado;
    }
    // Caso o número digitado for maior que o maior número atual, substitua-o
    if (numeroDigitado > maiorNumeroAtual) {
      maiorNumeroAtual = numeroDigitado;
    }
    // Caso o número digitado for menor que o menor número atual, substitua-o
    if (numeroDigitado < menorNumeroAtual) {
      menorNumeroAtual = numeroDigitado;
    }
    // Faça a soma
    soma = soma + numeroDigitado;

    quantidadeDeNumeros++;
  }

  // Caso for digitado apenas um número imprima a frase no singular
  if (quantidadeDeNumeros == 1) {
    printf("Foi inserido 1 número\n");
  } else {
    printf("Foram inseridos %d números\n", quantidadeDeNumeros);
  }
  printf("O maior número é %d\n", maiorNumeroAtual);
  printf("O menor número é %d\n", menorNumeroAtual);
  printf("A soma dos números é %d\n", soma);

  // Calculando a média
  media = (float)soma / quantidadeDeNumeros;

  printf("A média dos números é %f\n", media);

  return 0;
}