// ---Instruções da atividade---
// 2. Elabore uma função que retorne 1 caso o número inteiro passado como parâmetro é palíndromo. 
// Caso o número passado como parâmetro seja 0, negativo ou não ser palíndromo, deve ser retornado 0.

#include <stdio.h>

int VerificarSeEPalindromo(int num) {
  int digito1, digito2, digito3, digito4, digito5;

  // Rejeitar números menores ou iguais a 0
  if (num <= 0) {
    return 0;
  }

  // Separar os digitos do número

  // Pegue o resto da divisão por 10, ou seja, o último dígito
  digito1 = num % 10;
  // Subtraia os últimos dois digitos pelo último digito
  // Assim, divida por 10, para "remover" o 0
  digito2 = (num % 100 - digito1) / 10;
  // Subtraia os últimos três digitos pelos dois últimos digitos
  // Assim, divida por 100, para "remover" o 00
  digito3 = (num % 1000 - digito2) / 100;
  // Subtraia os últimos quatro digitos pelos três últimos digitos
  // Assim, divida por 1000, para "remover" o 000
  digito4 = (num % 10000 - digito3) / 1000;
  // Subtraia os últimos cinco digitos pelos quatro últimos digitos
  // Assim, divida por 10000, para "remover" o 0000
  digito5 = (num % 100000 - digito4) / 10000;

  // Caso o número tiver 5 dígitos
  if (num >= 10000) {
    // Verifique se o primeiro dígito é igual ao último
    // e se o segundo dígito é igual ao penúltimo
    if (digito1 == digito5 && digito2 == digito4) {
      return 1;
    }
  }
  // Caso o número tiver 4 dígitos
  else if (num >= 1000) {
    if (digito1 == digito4 && digito2 == digito3) {
      return 1;
    }
  }
  // Caso o número tiver 3 dígitos
  else if (num >= 100) {
    if (digito1 == digito3) {
      return 1;
    }
  }
  // Caso o número tiver 2 dígitos
  else if (num >= 10) {
    if (digito1 == digito2) {
      return 1;
    }
  }
  // Não considerando números de 1 dígito

  // Caso não for palíndromo retorne falso
  return 0;
}

int main(void) {
  short int num;

  // Loop para repetir o texto, caso não for digitado
  // um número menor do que 32768
  printf("Digite um número menor do que 32768\n");

  scanf("%hd", &num);

  // Se o número for palíndromo, imprima ele
  if (VerificarSeEPalindromo(num)) {
    printf("O número %d é palíndromo\n", num);
  } else {
    printf("O número não é palíndromo\n");
  }

  return 0;
}