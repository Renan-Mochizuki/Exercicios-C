// ---Instruções da atividade---
// 1. Escreva uma rotina que receba como parâmetro uma quantidade de números a serem inseridos e que 
// depois peça para que sejam digitados cada um desses números inteiros e positivos. Ao final, deve ser 
// mostrado quantos desses números são primos.

#include <stdio.h>

// Função para verificar se o número digitado é primo
int verificarSeEPrimo(int num) {

  // i = 2, pois o número 1 não conta
  int i = 2;

  // Rejeitar números menores que 2, pois o 1 não é primo
  if (num < 2) {
    return 0;
  }
  // Loop para verificar se o número é divisível por
  // qualquer um outro anterior à metade dele
  while (i <= num / 2) {
    // Se o número for divisível, retorne falso
    if (num % i == 0) {
      return 0;
    }
    i++;
  }

  // Retorne verdadeiro caso o número não seja divisível
  // por nenhum outro
  return 1;
}

int main() {
  short int numeroDigitado, quantidadeDeNumeros;
  int i = 0, k = 0, quantidadeDePrimos = 0;

  printf("Progama verificar quantos números são primos\n");
  printf("Digite a quantidade de números que serão digitados:\n");

  // Receber a quantidade de números que serão digitados
  scanf("%hd", &quantidadeDeNumeros);

  // Declarar uma array do tamanho da quantidade de números
  int numerosPrimos[quantidadeDeNumeros];

  printf("Digite %d números naturais\n", quantidadeDeNumeros);

  // Loop que receberá os números até a certa quantidade
  while (i < quantidadeDeNumeros) {
    scanf("%hd", &numeroDigitado);

    // Se for digitado um número negativo, pare o loop
    if (numeroDigitado < 0) {
      break;
    }
    // Caso o número for primo, adiciona na array de primos
    if (verificarSeEPrimo(numeroDigitado)) {
      numerosPrimos[quantidadeDePrimos] = numeroDigitado;
      quantidadeDePrimos++;
    }
    i++;
  }

  printf("Há %d números primos\n", quantidadeDePrimos);

  // Apenas imprimirá os textos caso houver pelo menos
  // um número primo
  if (quantidadeDePrimos > 0) {
    printf("Os números primos digitados são:\n");

    // Digitando apenas o primeiro número para que a
    // vírgula fique correta
    printf("%d", numerosPrimos[k]);
    k++;

    // Imprimindo os números primos com vírgula
    while (k < quantidadeDePrimos) {
      printf(", %d", numerosPrimos[k]);
      k++;
    }
  }

  return 0;
}