// ---Instruções da atividade---
// Apresentar uma rotina em C que dadas duas strings, apresente-as de forma ordenada alfabeticamente
// A comparação precisa ser feita caracter a caracter das strings

#include <stdio.h>
#include <string.h>

// Função que retorna 1 ou 2, indicando qual string vem primeiro
// alfabeticamente, ou 0 se forem exatamente iguais
int VerificarQualStringVemPrimeiro(char *string1, char *string2)
{
  // Variável que armazenará o valor do caractere pela tabela ASCII
  int valorConvertido1, valorConvertido2;

  // Inicializando como 32 para fazer a verificação do caractere espaço
  valorConvertido1 = 32, valorConvertido2 = 32;

  // Loop para previnir que o primeiro caractere analisado seja um espaço
  for (int i = 0; valorConvertido1 == 32; i++)
  {
    valorConvertido1 = (int)string1[i];
  }
  for (int i = 0; valorConvertido2 == 32; i++)
  {
    valorConvertido2 = (int)string2[i];
  }

  int i = 0, j = 0;

  // Loop que percorre as strings até encontrar o primeiro caractere diferente
  while (string1[i] != '\0' || string2[j] != '\0')
  {
    // Se o caractere pela tabela ASCII for menor que o outro
    if (valorConvertido1 < valorConvertido2)
    {
      return 1;
    }
    if (valorConvertido2 < valorConvertido1)
    {
      return 2;
    }
    // Se forem iguais, ande para o próximo caractere e
    // altere o próximo caractere
    i++;
    j++;
    valorConvertido1 = (int)string1[i];
    valorConvertido2 = (int)string2[j];
  }

  // Se as strings forem iguais e do mesmo tamanho
  return 0;
}

// Função para juntar duas strings, com um espaço entre elas
void JuntarStrings(char *string1, char *string2)
{
  // Usando a função strcat para concatenar
  strcat(string1, " ");
  strcat(string1, string2);
}

// Função que separa palavras de uma string em um vetor
void SepararPalavras(char *string, char (*vetorPalavras)[128], int *quantidade)
{
  char palavraAtual[128];
  int j = 0, k = 0;
  int quantidadeDePalavras = 0;

  // Loop que percorre toda a string separando cada palavra
  for (int i = 0; string[i] != '\0'; i++)
  {
    // Se o caractere atual for um espaço, vírgula ou ponto
    if (string[i] == ' ' || string[i] == ',' || string[i] == '.')
    {
      // Adicione um terminador de string
      palavraAtual[j] = '\0';
      // Adicione a palavra atual no vetor de palavras
      strcpy(vetorPalavras[k], palavraAtual);
      // Incremente a quantidade de palavras e resete a palavra atual
      k++;
      quantidadeDePalavras++;
      j = 0;
    }
    else
    {
      // Se a ainda não tiver chego no fim da palavra
      // vá para o próximo caractere
      palavraAtual[j] = string[i];
      j++;
    }
  }

  // Incluindo a última palavra que ficou de fora
  palavraAtual[j] = '\0';
  strcpy(vetorPalavras[k], palavraAtual);
  quantidadeDePalavras++;

  *quantidade = quantidadeDePalavras;
}

// Função ordenar vetor de palavras pelo Bubble Sort
void OrdenarVetorPalavras(char (*vetor)[128], int tamanho)
{
  int i = 0;
  int trocou = 0;
  do
  {
    trocou = 0;
    int criterioDoLoop = tamanho - 1 - i;
    for (int j = 0; j < criterioDoLoop; j++)
    {
      // Pegando o resultado da função que verifica qual string vem primeiro
      int resultadoF = VerificarQualStringVemPrimeiro(vetor[j], vetor[j + 1]);
      // Se a próxima string vier primeiro que a atual
      if (resultadoF == 2)
      {
        // Troque as strings de lugar
        char auxiliar[128];
        strcpy(auxiliar, vetor[j]);
        strcpy(vetor[j], vetor[j + 1]);
        strcpy(vetor[j + 1], auxiliar);
        trocou = 1;
      }
    }
    i++;
  } while (trocou == 1);
}

int main(void)
{
  char string1[128];
  char string2[128];

  printf("Digite dois textos, podendo ter espaços:\n");

  // Recebendo o texto, podendo ter espaços
  scanf(" %[^\n]", string1);
  scanf(" %[^\n]", string2);

  printf("\nOs textos, alfabeticamente, são:\n");

  // Verificando qual string vem primeiro
  int resultadoF = VerificarQualStringVemPrimeiro(string1, string2);

  if (resultadoF == 1)
  {
    printf("%s\n", string1);
    printf("%s\n", string2);
  }
  else if (resultadoF == 2)
  {
    printf("%s\n", string2);
    printf("%s\n", string1);
  }
  else
  {
    printf("Iguais: %s, %s\n", string1, string2);
  }

  // Vetor que pode armazenar 64 palavras de até 127 caracteres
  char vetorPalavras1[64][128];
  char vetorPalavras2[64][128];
  int quantidadeDePalavras1, quantidadeDePalavras2;

  // Separando todas as palavras de um string em uma matriz
  SepararPalavras(string1, vetorPalavras1, &quantidadeDePalavras1);
  SepararPalavras(string2, vetorPalavras2, &quantidadeDePalavras2);

  OrdenarVetorPalavras(vetorPalavras1, quantidadeDePalavras1);
  OrdenarVetorPalavras(vetorPalavras2, quantidadeDePalavras2);

  printf("\nOrdenando as palavras dos texto 1 temos:\n");

  for (int i = 0; i < quantidadeDePalavras1; i++)
  {
    printf("%s ", vetorPalavras1[i]);
  }

  printf("\n\nOrdenando as palavras dos texto 2 temos:\n");

  for (int i = 0; i < quantidadeDePalavras2; i++)
  {
    printf("%s ", vetorPalavras2[i]);
  }

  char vetorPalavras[128][128];
  int quantidadeDePalavras;

  // Juntando as duas strings na string1
  JuntarStrings(string1, string2);

  SepararPalavras(string1, vetorPalavras, &quantidadeDePalavras);

  OrdenarVetorPalavras(vetorPalavras, quantidadeDePalavras);

  printf("\n\nOrdenando as palavras de ambos textos ficam:\n");

  for (int i = 0; i < quantidadeDePalavras; i++)
  {
    printf("%s ", vetorPalavras[i]);
  }

  return 0;
}