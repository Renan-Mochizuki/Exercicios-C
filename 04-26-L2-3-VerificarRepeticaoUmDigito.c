// ---Instruções da atividade---
// 3. Apresente um rotina que dados os seguintes parâmetros: (1) um número inteiro positivo e maior 
// que zero e (2) um número inteiro de um único dígito. Essa rotina deve mostrar quantas vezes uma 
// repetição de dois números iguais ao segundo parâmetro aparece na sequência de dígitos do primeiro parâmetros. 
// Exemplos:
// a. caso o número seja (parâmetro 1) 344 e o segundo parâmetro seja o número 4 deve ser retornado o valor 1
// b. caso o número seja (parâmetro 1) 3444 e o segundo parâmetro seja o número 4 deve ser retornado o valor 2 (duas repetições de 44)
// c. caso o número seja (parâmetro 1) 3434 e o segundo parâmetro seja o número 4 deve ser retornado o valor 0
// d. caso o número seja (parâmetro 1) 8549 e o segundo parâmetro seja o número 4 deve ser retornado o valor 0

#include <stdio.h>

int VerificarQuantidadeRepeticoes(int num, int umdigito) {
  int digitos[5];
  int i = 0;
  int repeticoesContadas = 0;

  // Rejeitar números menores ou iguais a 0
  if (num <= 0) {
    return 0;
  }

  // Separar os digitos do número

  // Pegue o resto da divisão por 10, ou seja, o último dígito
  digitos[0] = num % 10;
  // Subtraia os últimos dois digitos pelo último digito
  // Assim, divida por 10, para "remover" o 0
  digitos[1] = (num % 100 - digitos[0]) / 10;
  // Subtraia os últimos três digitos pelos dois últimos digitos
  // Assim, divida por 100, para "remover" o 00
  digitos[2] = (num % 1000 - digitos[1]) / 100;
  // Subtraia os últimos quatro digitos pelos três últimos digitos
  // Assim, divida por 1000, para "remover" o 000
  digitos[3] = (num % 10000 - digitos[2]) / 1000;
  // Subtraia os últimos cinco digitos pelos quatro últimos digitos
  // Assim, divida por 10000, para "remover" o 0000
  digitos[4] = (num % 100000 - digitos[3]) / 10000;

  // Loop para verificar se um dígito e seu próximo são
  // iguais ao único dígito
  while (i < 5) {
    if (digitos[i] == umdigito && digitos[i+1] == umdigito) {
      repeticoesContadas++;
    }
    i++;
  }

  return repeticoesContadas;
}

int main(void) {
  short int num, umdigito;
  int quantidadeDeRepeticoes;

  // Loop para repetir o texto, caso não for digitado
  // um número menor do que 32768
  printf("Digite um número menor do que 32768\n");

  scanf("%hd", &num);

  // Loop para ficar pedindo, caso não for digitado
  // um número de um único dígito
  while (1){
    printf("Digite um número de um único dígito\n");

    scanf("%hd", &umdigito);

    if(umdigito < 10){
      break;
    }
  }

  quantidadeDeRepeticoes = VerificarQuantidadeRepeticoes(num, umdigito);

  printf("No número %hd, o número %hd%hd se repete %d vezes\n", num, umdigito, umdigito, quantidadeDeRepeticoes);

  return 0;
}