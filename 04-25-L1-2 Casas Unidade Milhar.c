// ---Instruções da atividade---
// 2. Entrar com um número inteiro positivo e menor que 10.000 e informar o valor de sua casa na
// unidade, na dezena, na centena e no milhar

#include <stdio.h>

int main(void)
{
  int num, digito, digito1, digito2, digito3, digito4;

  while (1 != 0)
  {
    printf("Digite um número menor do que 10000\n");

    scanf("%d", &num);

    if (num < 10000)
    {
      // Pegue o resto da divisão por 10, ou seja, o último dígito
      digito1 = num % 10;
      printf("A casa da unidade é: %d\n", digito1);
      // Pegue os últimos dois dígitos
      digito2 = num % 100;
      // Subtraia os últimos dois digitos pelo último digito
      // Assim, divida por 10, para "remover" o 0
      digito = (digito2 - digito1) / 10;
      printf("A casa da dezena é: %d\n", digito);
      // Pegue os últimos três dígitos
      digito3 = num % 1000;
      // Subtraia os últimos três digitos pelos dois últimos digitos
      // Assim, divida por 100, para "remover" o 00
      digito = (digito3 - digito2) / 100;
      printf("A casa da centena é: %d\n", digito);
      // Pegue os últimos quatro dígitos
      digito4 = num % 10000;
      // Subtraia os últimos quatro digitos pelos três últimos digitos
      // Assim, divida por 1000, para "remover" o 000
      digito = (digito4 - digito3) / 1000;
      printf("A casa da unidade de milhar é: %d\n", digito);
      break;
    }
  }

  return 0;
}