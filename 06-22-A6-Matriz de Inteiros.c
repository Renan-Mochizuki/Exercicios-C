// ---Instruções da atividade---
// Apresente (codifique e rode) um programa em C com as seguintes rotinas:
// 1. Definição de uma matriz de inteiros de no máximo 10 x 10 posições
// 2. Uma rotina para serem inseridos elementos inteiros nessa matriz
// 3. Rotinas para:
// - mostrar o maior elemento de cada linha
// - mostrar o maior elemento de cada coluna
// - mostrar o menor elemento de cada linha
// - mostrar o maior elemento de cada coluna
// 4. rotinas para 
// - mostrar em quais linha e coluna está o maior elemento da matriz
// - mostrar em quais linha e coluna está o menor elemento da matriz
// - mostrar a soma dos valores de cada linha
// - mostrar a soma dos valores de cada coluna
// - mostrar qual linha possui a maior soma dos valores de cada linha
// - mostrar qual colunapossui a maior soma dos valores de cada coluna

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InserirValor(int matriz[10][10], int valor, int *ultimaPosInserida) {
  int ultimaLinha = ultimaPosInserida[0];
  int ultimaColuna = ultimaPosInserida[1];

  // Se a ultima posição tiver chego no final da linha, resete e vá para a
  // próxima linha
  if (ultimaLinha == 9) {
    ultimaPosInserida[1] = 0;
    ultimaPosInserida[0]++;
  } else {
    // Ande de casa na linha
    ultimaPosInserida[1]++;
  }

  matriz[ultimaLinha][ultimaColuna] = valor;
}

void ImprimirMatriz(int matriz[10][10]) {
  // Loop para percorrer todas as linhas
  for (int i = 0; i < 10; i++) {
    // Loop para percorrer toda essa linha
    for (int j = 0; j < 10; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void ImprimirMaiorMenorCadaLinha(int matriz[10][10]) {
  // Loop para percorrer todas as linhas
  for (int i = 0; i < 10; i++) {
    // Definindo o maior e menor como o primeiro valor da linha
    int maiorNum = matriz[i][0];
    int menorNum = matriz[i][0];
    // Loop para percorrer toda essa linha
    for (int j = 1; j < 10; j++) {
      // Se o valor atual for maior que o maiorNum, atualize o maiorNum
      if (matriz[i][j] > maiorNum) {
        maiorNum = matriz[i][j];
      }
      if (matriz[i][j] < menorNum) {
        menorNum = matriz[i][j];
      }
    }
    printf("%d: Maior: %d, Menor: %d", i + 1, maiorNum, menorNum);
    printf("\n");
  }
}

void ImprimirMaiorMenorCadaColuna(int matriz[10][10]) {
  // Loop para percorrer todas colunas
  for (int i = 0; i < 10; i++) {
    // Definindo o maior e menor como o primeiro valor da coluna
    int maiorNum = matriz[0][i];
    int menorNum = matriz[0][i];
    // Loop para percorrer toda essa coluna
    for (int j = 1; j < 10; j++) {
      // Se o valor atual for maior que o maiorNum, atualize o maiorNum
      if (matriz[j][i] > maiorNum) {
        maiorNum = matriz[j][i];
      }
      if (matriz[j][i] < menorNum) {
        menorNum = matriz[j][i];
      }
    }
    printf("%d: Maior: %d, Menor: %d", i + 1, maiorNum, menorNum);
    printf("\n");
  }
}

void ImprimirMaiorMenorMatriz(int matriz[10][10]) {
  // Definindo o maior e menor como o primeiro valor da matriz
  int maiorNum = matriz[0][0];
  int menorNum = matriz[0][0];
  // Variável que armazena a posição do maiorNum e menorNum
  int PosMaiorNum[2] = {0, 0};
  int PosMenorNum[2] = {0, 0};
  // Loop para percorrer todas as linhas
  for (int i = 0; i < 10; i++) {
    // Loop para percorrer toda essa linha
    for (int j = 1; j < 10; j++) {
      // Se o valor atual for maior que o maiorNum, atualize o maiorNum
      if (matriz[i][j] > maiorNum) {
        maiorNum = matriz[i][j];
        PosMaiorNum[0] = i;
        PosMaiorNum[1] = j;
      }
      if (matriz[i][j] < menorNum) {
        menorNum = matriz[i][j];
        PosMenorNum[0] = i;
        PosMenorNum[1] = j;
      }
    }
  }
  printf("Maior: %d, Linha: %d, Coluna: %d\n", maiorNum, PosMaiorNum[0] + 1,
         PosMaiorNum[1] + 1);
  printf("Menor: %d, Linha: %d, Coluna: %d\n", menorNum, PosMenorNum[0] + 1,
         PosMenorNum[1] + 1);
}

int RetornarSomaDaLinha(int matriz[10][10], int linha) {
  int soma = 0;
  // Loop que percorre toda a linha
  for (int i = 0; i < 10; i++) {
    soma += matriz[linha][i];
  }
  return soma;
}

int RetornarSomaDaColuna(int matriz[10][10], int coluna) {
  int soma = 0;
  // Loop que percorre toda a coluna
  for (int i = 0; i < 10; i++) {
    soma += matriz[i][coluna];
  }
  return soma;
}

void ImprimirSomaCadaLinha(int matriz[10][10]) {
  // Loop que percorre todas as linhas
  for (int i = 0; i < 10; i++) {
    int soma = RetornarSomaDaLinha(matriz, i);
    printf("%d: %d\n", i + 1, soma);
  }
}

void ImprimirSomaCadaColuna(int matriz[10][10]) {
  // Loop que percorre todas as colunas
  for (int i = 0; i < 10; i++) {
    int soma = RetornarSomaDaColuna(matriz, i);
    printf("%d: %d\n", i + 1, soma);
  }
}

void ImprimirMaiorMenorSomaLinha(int matriz[10][10]) {
  // Definindo a maior e menor soma como a soma da primeira linha
  int somaPrimeiraLinha = RetornarSomaDaLinha(matriz, 0);
  int maiorSomaLinha = somaPrimeiraLinha;
  int menorSomaLinha = somaPrimeiraLinha;
  int maiorNumLinha = 0;
  int menorNumLinha = 0;

  // Loop que percorre todas as linhas
  for (int i = 1; i < 10; i++) {
    // Faz a soma da linha e verifica se é maior e menor
    int somaLinhaAtual = RetornarSomaDaLinha(matriz, i);
    if (somaLinhaAtual > maiorSomaLinha) {
      maiorSomaLinha = somaLinhaAtual;
      maiorNumLinha = i;
    }
    if (somaLinhaAtual < menorSomaLinha) {
      menorSomaLinha = somaLinhaAtual;
      menorNumLinha = i;
    }
  }

  printf("Maior: %d, Linha: %d\n", maiorSomaLinha, maiorNumLinha + 1);
  printf("Menor: %d, Linha: %d\n", menorSomaLinha, menorNumLinha + 1);
}

void ImprimirMaiorMenorSomaColuna(int matriz[10][10]) {
  // Definindo a maior e menor soma como a soma da primeira coluna
  int somaPrimeiraColuna = RetornarSomaDaColuna(matriz, 0);
  int maiorSomaColuna = somaPrimeiraColuna;
  int menorSomaColuna = somaPrimeiraColuna;
  int maiorNumColuna = 0;
  int menorNumColuna = 0;

  // Loop que percorre todas as coluna
  for (int i = 1; i < 10; i++) {
    // Faz a soma da coluna e verifica se é maior e menor
    int somaColunaAtual = RetornarSomaDaColuna(matriz, i);
    if (somaColunaAtual > maiorSomaColuna) {
      maiorSomaColuna = somaColunaAtual;
      maiorNumColuna = i;
    }
    if (somaColunaAtual < menorSomaColuna) {
      menorSomaColuna = somaColunaAtual;
      menorNumColuna = i;
    }
  }

  printf("Maior: %d, Coluna: %d\n", maiorSomaColuna, maiorNumColuna + 1);
  printf("Menor: %d, Coluna: %d\n", menorSomaColuna, menorNumColuna + 1);
}

int main(void) {
  int numeroDigitado;
  int matriz[10][10];
  // Variável que armazena a última posição que foi inserida um valor na matriz
  int ultimaPosInserida[2] = {0, 0};
  // Inicialização necessária para gerar números aleatórios
  srand(time(NULL));

  printf("Insira valores na matriz:\n");
  printf("Ou digite um número negativo para preencher aleatoriamente\n");
  // Loop que pedirá todos os 100 valores
  for (int i = 0; i < 100; i++) {
    scanf("%d", &numeroDigitado);
    // Se for digitado um número negativo, preenche aleatoriamente
    if (numeroDigitado < 0) {
      // Pegando o valor absoluto da última posição
      int iDaUltimaPos = ultimaPosInserida[0] * 10 + ultimaPosInserida[1];
      for (int i = iDaUltimaPos; i < 100; i++) {
        // Inserindo um número aleatório na matriz
        int valorAleatorio = rand() % 101;
        InserirValor(matriz, valorAleatorio, ultimaPosInserida);
      }
      break;
    } else {
      InserirValor(matriz, numeroDigitado, ultimaPosInserida);
    }
  }

  printf("A matriz está assim:\n");
  ImprimirMatriz(matriz);

  printf("\nOs maiores e menores elementos de cada linha são:\n");
  ImprimirMaiorMenorCadaLinha(matriz);

  printf("\nOs maiores e menores elementos de cada coluna são:\n");
  ImprimirMaiorMenorCadaColuna(matriz);

  printf("\nO maior e menor elemento da matriz são:\n");
  ImprimirMaiorMenorMatriz(matriz);

  printf("\nA soma de cada linha é:\n");
  ImprimirSomaCadaLinha(matriz);

  printf("\nA soma de cada coluna é:\n");
  ImprimirSomaCadaColuna(matriz);

  printf("\nA maior e menor soma das linhas é:\n");
  ImprimirMaiorMenorSomaLinha(matriz);

  printf("\nA maior e menor soma das colunas é:\n");
  ImprimirMaiorMenorSomaColuna(matriz);

  return 0;
}