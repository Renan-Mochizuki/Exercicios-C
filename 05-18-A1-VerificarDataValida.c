// ---Instruções da atividade---
// Apresentar um programa na linguagem C que peça que seja digitada uma data (DD/MM/AAAA) e 
// informe se essa data é válida ou não.
// Lembrando que se um ano for divisível por quatro é um ano bissexto e, portanto, o dia 29 de 
// fevereiro é uma data válida.

#include <stdio.h>
#include <string.h>

int VerificarData(int dia, int mes, int ano) {
  // Se o mês for menor que 1 ou maior que 12 ou o dia
  // for menor que 1, retorna falso
  if (mes < 1 || mes > 12 || dia < 1) {
    return 0;
  }

  // Se o mês for fevereiro, o ano não for bissexto e
  // o dia for maior que 28, retorna falso
  if (mes == 2 && ano % 4 != 0 && dia > 28) {
    return 0;
  }
  // Se o mês for fevereiro e o ano for bissexto
  // permite o dia ser até 29
  if (mes == 2 && ano % 4 == 0 && dia > 29) {
    return 0;
  }
  // Se o mês tiver 31 dias
  if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
    
    // Se o dia for maior que 31, retorna falso
    if (dia > 31) {
      return 0;
    }
    
  } else { // Para todos os meses com 30 dias (Fevereiro ja foi excluido)
    
    if (dia > 30) {
      return 0;
    }
    
  }

  return 1;
}

int main(void) {

  // Tamanho 11 porque o último caractere é o \0
  char data[11];
  int tamanhoDoVetor;
  int dia, mes, ano;

  // Loop para continuar perguntando até que o usuário
  // digite uma data válida
  while (1) {
    printf("Digite a data no formato DD/MM/AAAA:\n");
    // Inserir um texto de 10 digitos em cada posição do vetor
    scanf(" %10[^\n]", data);

    // Usando strlen da <string.h> para ver quantos digitos
    // foram digitados
    tamanhoDoVetor = strlen(data);

    // Se o tamanho for 10, pare o loop
    if (tamanhoDoVetor != 10) {
      printf("A data digitada não está no formato\n");
    } else {
      break;
    };
  }

  // Separando os valores digitados para cada variável
  // Convertendo o texto para inteiro subtraindo '0'
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[3] - '0') * 10 + (data[4] - '0');
  ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

  if (VerificarData(dia, mes, ano)) {
    printf("Data válida!\n");
  } else {
    printf("Data inválida!\n");
  }

  return 0;
}