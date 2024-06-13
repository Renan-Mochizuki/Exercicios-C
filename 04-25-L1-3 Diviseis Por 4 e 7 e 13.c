// ---Instruções da atividade---
// 3. Entrar com N números e entre os números digitados dizer: (a) quantos são divisíveis por 4; 
// (b) quantos são divisíveis por 7; e (c) quantos são divisíveis por 13.

#include <stdio.h>

int main(void)
{
  int numeros[128];
  int i = 0, k = 0;
  int somaDivisivelPor4 = 0, somaDivisivelPor7 = 0, somaDivisivelPor13 = 0;

  printf("Insira os números com limite até 128 números\n");
  printf("Para parar o programa digite um número negativo\n");

  // Loop para receber todos os números e armazená-los em uma array até o limite de 128 números
  while (i < 128)
  {
    int numeroDigitado;
    scanf("%d", &numeroDigitado);
    // Caso o número digitado seja negativo, o loop é interrompido
    if (numeroDigitado < 0)
    {
      break;
    }
    numeros[i] = numeroDigitado;
    i++;
  }

  // Loop que percorre toda a array
  while (k < i)
  {
    // Se o número for divisível por 4, aumente a quantidade de números divisíveis por 4
    if (numeros[k] % 4 == 0)
    {
      somaDivisivelPor4++;
    }
    // Se o número for divisível por 7, aumente a quantidade de números divisíveis por 7
    if (numeros[k] % 7 == 0)
    {
      somaDivisivelPor7++;
    }
    // Se o número for divisível por 13, aumente a quantidade de números divisíveis por 13
    if (numeros[k] % 13 == 0)
    {
      somaDivisivelPor13++;
    }
    k++;
  }

  printf("Há no total:\n");
  printf("%d números divisíveis por 4\n", somaDivisivelPor4);
  printf("%d números divisíveis por 7\n", somaDivisivelPor7);
  printf("%d números divisíveis por 13\n", somaDivisivelPor13);

  return 0;
}