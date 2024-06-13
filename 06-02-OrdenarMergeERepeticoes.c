// ---Instruções da atividade---
// Elabore um programa em C que:
// a) Crie 2 vetores de inteiros positivos (maiores ou iguais a 0) distintos que tenham tamanho máximo de 20 elementos cada. E insira elementos para cada um dos vetores, onde o critério de parada para inserção dos elementos em um vetor é a inserção do 20º elemento ou que seja inserido um valor negativo.
// b) Ordene, de forma crescente, cada um desses vetores.
// c) Crie 2 novos vetores de inteiros (de tamanho máximo 40) para que:
// 1. O terceiro vetor seja um merge * dos outros dois iniciais e esses devem ser passados como parâmetro para uma rotina específica. Este terceiro vetor não terá valores repetidos.
// 2. O quarto vetor contenha os elementos que indicaram alguma repetição de valores que estejam nos dois vetores iniciais.
// Obs: Cuidado!!! Pois podem haver repetições de valores nos vetores iniciais e lembrem que o vetor do “merge” não pode haver repetições.
// d) Apresente (mostre na tela) cada um dos elementos de todos os vetores em cada etapa.
// e) Apresente os valores e quantidade de repetições que ocorreram nos dois vetores iniciais
// f) Coloquem comentários em seus códigos, descrevendo o que cada rotina faz e o que ocorre em cada etapa.

#include <stdio.h>

int OrdenarVetor(int *vetor, int tamanho)
{
  // Loop para ignorar os elementos que já foram ordenados
  for (int i = 0; i < tamanho; i++)
  {

    int criterioDoLoop = tamanho - 1 - i;
    // tamanho-1, pois verificaremos o elemento atual com o próximo, portanto,
    // não devemos comparar o último elemento
    //
    // -i, pois o maior elemento sempre vai para o final da lista a cada
    // interação, portanto não é necessário verificar os últimos elementos que
    // já ficaram ordenados

    // Loop que percorre o vetor
    for (int j = 0; j < criterioDoLoop; j++)
    {
      // Se o número da posição atual for maior do que o número da próxima
      // posição
      if (vetor[j] > vetor[j + 1])
      {
        // Faça a troca entre eles utilizando um auxiliar
        int auxiliar = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = auxiliar;
      }
    }
  }

  return 0;
}

int MergeVetorERepeticoes(int vetor1[], int vetor2[], int tamanhoVetor1, int tamanhoVetor2, int *vetor3, int *vetor4, int *tamanhoVetor3, int *tamanhoVetor4)
{
  // Criando um vetor temporario
  int tamanhoVetorSimples = tamanhoVetor1 + tamanhoVetor2;
  int vetorSimples[tamanhoVetorSimples];

  // Loop para inserir o vetor1 no vetor simples
  for (int i = 0; i < tamanhoVetor1; i++)
  {
    vetorSimples[i] = vetor1[i];
  }

  int indiceSimples = tamanhoVetor1;
  // Loop para inserir mais o vetor2 no vetor simples
  for (int i = 0; i < tamanhoVetor2; i++)
  {
    vetorSimples[indiceSimples] = vetor2[i];
    indiceSimples++;
  }

  // Ordenando o vetor simples
  OrdenarVetor(vetorSimples, tamanhoVetorSimples);

  // Definindo o primeiro item do vetor3 como o primeiro item do vetor simples
  vetor3[0] = vetorSimples[0];

  // Criando um indice para o vetor3
  int i3 = 1;
  int i4 = 0;

  // Loop para percorrer todo o vetor simples depois do primeiro item
  for (int i = 1; i < tamanhoVetorSimples; i++)
  {

    // Se o item anterior do vetor3 for diferente do item atual do vetor simples
    if (vetor3[i3 - 1] != vetorSimples[i])
    {
      // Insira o item atual no vetor3
      vetor3[i3] = vetorSimples[i];
      i3++;
    }
    //  Se o item for repetido
    else
    {
      // Se o item repetido já tiver sido inserido no vetor4s
      if (vetor4[i4 - 1] != vetorSimples[i])
      {
        //  Adicione o item na array de itens repetidos
        vetor4[i4] = vetorSimples[i];
        i4++;
      }
    }
  }

  // Alterando o tamanho do vetor3 e do vetor4 para acessar ele na main
  *tamanhoVetor3 = i3;
  *tamanhoVetor4 = i4;

  return 0;
}

int VerificarRepeticaoEntreVetores(int vetorOrdenado1[], int vetorOrdenado2[], int tamanho1, int tamanho2, int *vetorRepeticoesValores, int *vetorRepeticoesQuantidades, int *tamanhoVetor)
{
  int i = 0, j = 0, k = 0, posicaoAtual = 0;

  // Loop para percorrer todo o vetor1 fazendo a verificação
  for (i = 0; i < tamanho1; i++)
  {
    // Loop para percorrer todo o vetor2
    for (j = posicaoAtual; j < tamanho2; j++)
    {
      if (vetorOrdenado1[i] == vetorOrdenado2[j])
      {

        // Se o valor atual for diferente do valor anterior repetido
        if (vetorOrdenado1[i] != vetorRepeticoesValores[k - 1])
        {
          // Adicione o valor atual no vetor de valores repetidos e aumente a
          // quantidade
          vetorRepeticoesValores[k] = vetorOrdenado1[i];
          vetorRepeticoesQuantidades[k] = 1;
          k++;
        }
        // Se o valor atual for igual ao valor anterior repetido
        else
        {
          // Some a quantidade de repetições
          vetorRepeticoesQuantidades[k - 1]++;
        }
        // Definindo a posição atual para que o loop não verifique o mesmo valor
        posicaoAtual = j + 1;
        // Parando o loop caso tiver achado uma repetição
        break;
      }
    }
  }

  // Alterando o valor do tamanho do vetor
  *tamanhoVetor = k;

  return 0;
}

int VerificarRepeticaoVetor(int vetorOrdenado[], int tamanho, int *vetorRepeticoesValores, int *vetorRepeticoesQuantidades, int *tamanhoVetor)
{
  int j = 0;

  // Loop para percorrer todo o vetor fazendo a verificação
  for (int i = 0; i < tamanho - 1; i++)
  {
    // Se o valor atual for igual ao próximo valor
    if (vetorOrdenado[i] == vetorOrdenado[i + 1])
    {

      // Se o valor atual for diferente do valor anterior repetido
      if (vetorOrdenado[i] != vetorRepeticoesValores[j - 1])
      {
        // Adicione o valor atual no vetor de valores repetidos e aumente a
        // quantidade
        vetorRepeticoesValores[j] = vetorOrdenado[i];
        vetorRepeticoesQuantidades[j] = 1;
        j++;
      }
      // Se o valor atual for igual ao valor anterior repetido
      else
      {
        // Some a quantidade de repetições
        vetorRepeticoesQuantidades[j - 1]++;
      }
    }
  }

  // Alterando o valor do tamanho do vetor
  *tamanhoVetor = j;

  return 0;
}

int main(void)
{
  int vetor1[20], vetor2[20];
  int vetor3[40], vetor4[40];
  int numeroDigitado;
  int indice1, indice2;
  int tamanhoVetor3, tamanhoVetor4;

  int vetorRepeticoesValores[40], vetorRepeticoesValores1[40], vetorRepeticoesValores2[40];
  int vetorRepeticoesQuantidades[40] = {0};
  int vetorRepeticoesQuantidades1[40] = {0};
  int vetorRepeticoesQuantidades2[40] = {0};
  int tamanhoVetorRepeticao, tamanhoVetorRepeticao1, tamanhoVetorRepeticao2;

  printf("Digite 20 inteiros\n");
  printf("Digite um número negativo para parar\n");

  // Loop para receber os valores
  for (indice1 = 0; indice1 < 20; indice1++)
  {
    scanf("%d", &numeroDigitado);
    if (numeroDigitado < 0)
    {
      break;
    }
    vetor1[indice1] = numeroDigitado;
  }

  printf("\nDigite mais 20 inteiros\n");
  printf("Digite um número negativo para parar\n");

  // Loop para receber os valores
  for (indice2 = 0; indice2 < 20; indice2++)
  {
    scanf("%d", &numeroDigitado);
    if (numeroDigitado < 0)
    {
      break;
    }
    vetor2[indice2] = numeroDigitado;
  }

  // Trocando nome da variável
  int tamanho1 = indice1;
  int tamanho2 = indice2;

  // Chamando a função para ordenar os vetores
  OrdenarVetor(vetor1, tamanho1);
  OrdenarVetor(vetor2, tamanho2);

  printf("\n\nO vetor1 ordenado é:\n");

  // Loop para imprimir o vetor1
  for (int i = 0; i < tamanho1; i++)
  {
    printf("%d, ", vetor1[i]);
  }

  printf("\n\nO vetor2 ordenado é:\n");

  // Loop para imprimir o vetor1
  for (int i = 0; i < tamanho2; i++)
  {
    printf("%d, ", vetor2[i]);
  }

  // Chamando a função para juntar os vetores e retornar o tamanho do vetor3
  MergeVetorERepeticoes(vetor1, vetor2, tamanho1, tamanho2, vetor3, vetor4, &tamanhoVetor3, &tamanhoVetor4);

  printf("\n\nO merge dos vetores é:\n");

  // Loop para imprimir o vetor3
  for (int i = 0; i < tamanhoVetor3; i++)
  {
    printf("%d, ", vetor3[i]);
  }

  // Verifica se há pelo menos um item repetido
  if (tamanhoVetor4 < 0)
  {
    printf("Não há nenhum valor repetido\n");
  }
  // Se houver pelo menos um item repetido
  else
  {
    printf("\n\nOs valores repetidos encontrados são:\n");

    // Loop para imprimir o vetor4
    for (int i = 0; i < tamanhoVetor4; i++)
    {
      printf("%d, ", vetor4[i]);
    }

    // Chamando a função para verificar as repeticoes entre os vetores
    VerificarRepeticaoEntreVetores(vetor1, vetor2, tamanho1, tamanho2, vetorRepeticoesValores, vetorRepeticoesQuantidades, &tamanhoVetorRepeticao);

    // Verifica se há pelo menos um item repetido entre os vetores
    if (tamanhoVetorRepeticao > 0)
    {
      printf("\n\nEntre os vetores:\n");

      // Loop para imprimir os valores repetidos entre os vetores
      for (int i = 0; i < tamanhoVetorRepeticao; i++)
      {
        printf("O %d aparece em ambos vetores %d vez(es)\n", vetorRepeticoesValores[i], vetorRepeticoesQuantidades[i]);
      }
    }
    else
    {
      printf("\nNão há valores repetidos entre os vetores\n");
    }

    // Chamando a função para verificar as repetições em cada vetor
    VerificarRepeticaoVetor(vetor1, tamanho1, vetorRepeticoesValores1, vetorRepeticoesQuantidades1, &tamanhoVetorRepeticao1);
    VerificarRepeticaoVetor(vetor2, tamanho2, vetorRepeticoesValores2, vetorRepeticoesQuantidades2, &tamanhoVetorRepeticao2);

    // Verifica se há pelo menos um item repetido no vetor1
    if (tamanhoVetorRepeticao1 > 0)
    {
      printf("\nNo vetor1:\n");

      // Loop para imprimir os valores repetidos do vetor1
      for (int i = 0; i < tamanhoVetorRepeticao1; i++)
      {
        printf("O %d se repete %d vez(es) no vetor1\n", vetorRepeticoesValores1[i], vetorRepeticoesQuantidades1[i]);
      }
    }
    else
    {
      printf("\nNão há valores repetidos no vetor1\n");
    }

    // Verifica se há pelo menos um item repetido no vetor2
    if (tamanhoVetorRepeticao2 > 0)
    {
      printf("\nNo vetor2:\n");

      // Loop para imprimir os valores repetidos do vetor2
      for (int i = 0; i < tamanhoVetorRepeticao2; i++)
      {
        printf("O %d se repete %d vez(es) no vetor2\n", vetorRepeticoesValores2[i], vetorRepeticoesQuantidades2[i]);
      }
    }
    else
    {
      printf("\nNão há valores repetidos no vetor2\n");
    }
  }

  return 0;
}