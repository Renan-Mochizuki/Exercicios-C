// ---Instruções da atividade---
// Apresente (implementado) um programa em C que execute um jogo da velha entre dois jogadores (A e B).
// A cada jogada o programa deve informar se houve um vencedor. Caso as 9 posições da matriz (3x3) representativa
// do jogo da velha tenham sido preenchidas e não houve vencedor, o programa deve informar que houve empate

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ImprimirTabuleiro(int matriz[3][3]) {
  // Percorre todos os itens
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Se for 0, imprime um espaço, 1 X e 2 O
      switch (matriz[i][j]) {
      case 0:
        printf("   ");
        break;
      case 10:
        printf(" X ");
        break;
      case 20:
        printf(" O ");
        break;
      default:
        printf(" %d ", matriz[i][j]);
        break;
      }
      // Previnir que seja impresso a barra no final
      if (j != 2) {
        printf("|");
      }
    }
    printf("\n");
    // Previnir que seja impresso a linha no final
    if (i != 2) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

void LimparTabuleiro(int matriz[3][3]) {
  // Percorre todos os itens colocando 0
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matriz[i][j] = 0;
    }
  }
}

int VerificarJogada(int matriz[3][3], int posicao) {
  // Obtendo a linha e a coluna a partir da posição
  int linha = (posicao - 1) / 3;
  int coluna = (posicao - 1) % 3;

  // Se a posição não estiver vazia, retorna 0
  if (matriz[linha][coluna] > 0) {
    return 0;
  }
  // Se estiver retorna 1
  return 1;
}

void InserirJogada(int matriz[3][3], int posicao, int jogador) {
  // Obtendo a linha e a coluna a partir da posição
  int linha = (posicao - 1) / 3;
  int coluna = (posicao - 1) % 3;
  matriz[linha][coluna] = jogador;
  ImprimirTabuleiro(matriz);
}

// Retorna 1 ou 2 dependendo do jogador que ganhar ou 0 se não houver ganhador
int VerificarVitoria(int matriz[3][3]) {
  // Percorre todas as linhas fazendo a comparação
  for (int i = 0; i < 3; i++) {
    // Se toda a linha for do mesmo valor
    if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
      // Se esse valor for 10, retorna 1 ou 20 retorna 2
      if (matriz[i][0] == 10) {
        return 1;
      } else if (matriz[i][0] == 20) {
        return 2;
      }
    }
  }
  // Percorre todas as colunas fazendo a comparação
  for (int i = 0; i < 3; i++) {
    // Se toda a coluna for do mesmo valor
    if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
      // Se esse valor for 10, retorna 1 ou 20 retorna 2
      if (matriz[0][i] == 10) {
        return 1;
      } else if (matriz[0][i] == 20) {
        return 2;
      }
    }
  }
  // Verifica a diagonal
  if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
    // Se esse valor for 10, retorna 1 ou 20 retorna 2
    if (matriz[1][1] == 10) {
      return 1;
    } else if (matriz[1][1] == 20) {
      return 2;
    }
  }
  // Verifica a outra diagonal
  if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
    // Se esse valor for 10, retorna 1 ou 20 retorna 2
    if (matriz[1][1] == 10) {
      return 1;
    } else if (matriz[1][1] == 20) {
      return 2;
    }
  }
  // Se não houver vencedor, retorna 0
  return 0;
}

int InverterJogador(int jogadorAtual) {
  if (jogadorAtual == 10) {
    jogadorAtual = 20;
  } else {
    jogadorAtual = 10;
  }
  return jogadorAtual;
}

int main(void) {
  int matriz[3][3];
  int opcaoDeJogoEscolhida = 0;
  int jogadorAtual = 10;
  int jogadaValida = 0, resultadoVerificacao = 0;
  int posicaoJogada;
  int quantidadeJogadas = 0;
  int vitoriasJogador1 = 0, vitoriasJogador2 = 0, empates = 0;
  // Inicialização necessária para gerar números aleatórios
  srand(time(NULL));

  // Loop para continuar perguntando
  while (opcaoDeJogoEscolhida != 1 && opcaoDeJogoEscolhida != 2) {
    printf("Digite 1 para jogar alternadamente, ou 2 para jogar contra o computador:\n");
    scanf("%d", &opcaoDeJogoEscolhida);
  }

  printf("Para jogar, considere as seguintes posições:\n\n");
  // Loop para preencher a matriz de 1 a 9
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matriz[i][j] = i * 3 + j + 1;
    }
  }
  ImprimirTabuleiro(matriz);
  LimparTabuleiro(matriz);

  // Se for escolhido jogar alternadamente
  if (opcaoDeJogoEscolhida == 1) {
    // Loop para jogar vários jogos
    while (1) {
      // Loop para continuar jogando até que alguém ganhe ou sejam feitas 9 jogadas
      while (resultadoVerificacao == 0 && quantidadeJogadas < 9) {
        if (jogadorAtual == 10) {
          printf("É a vez do Jogador 1 (X)\n");
        } else {
          printf("É a vez do Jogador 2 (O)\n");
        }
        // Loop para continuar perguntando se a jogada não for válida
        while (jogadaValida == 0) {
          printf("Digite uma posição\n");
          scanf("%d", &posicaoJogada);
          // Para o jogo se for digitado um número negativo
          if (posicaoJogada < 0) {
            printf("\nO jogador 1 teve %d vitórias\n", vitoriasJogador1);
            printf("O jogador 2 teve %d vitórias\n", vitoriasJogador2);
            printf("Aconteceram %d empates\n", empates);
            return 0;
          }
          // Verifica se a posição jogada é válida
          jogadaValida = VerificarJogada(matriz, posicaoJogada);
          // Se a jogada for válida, insere a jogada e aumenta a sua quantidade
          if (jogadaValida) {
            InserirJogada(matriz, posicaoJogada, jogadorAtual);
            quantidadeJogadas++;
          } else {
            printf("Essa posição já está ocupada!\n");
          }
        }
        resultadoVerificacao = VerificarVitoria(matriz);
        // Inverte o jogador atual e reseta jogadaValida
        jogadorAtual = InverterJogador(jogadorAtual);
        jogadaValida = 0;
      }
      if (resultadoVerificacao == 1) {
        printf("O jogador 1 (X) ganhou!\n");
        vitoriasJogador1++;
        // Invertendo jogador para que o ganhador comece o próximo jogo
        jogadorAtual = InverterJogador(jogadorAtual);
      } else if (resultadoVerificacao == 2) {
        printf("O jogador 2 (O) ganhou!\n");
        vitoriasJogador2++;
        // Invertendo jogador para que o ganhador comece o próximo jogo
        jogadorAtual = InverterJogador(jogadorAtual);
      } else {
        printf("O jogo deu empate\n");
        empates++;
      }
      // Resetando tabuleiro, resultadoVerificacao e quantidadeJogadas
      LimparTabuleiro(matriz);
      resultadoVerificacao = 0;
      quantidadeJogadas = 0;
      
      printf("\n\nNovo jogo começando\n");
      printf("Ou digite um número negativo para parar e ver resultados\n\n\n");
    }
  }
  // Se for escolhido jogar contra computador
  else {
    printf("O computador escolherá casas aleatórias para jogar\n\n");
    // Loop para jogar vários jogos
    while (1) {
      // Loop para continuar jogando até que alguém ganhe ou sejam feitas 9 jogadas
      while (resultadoVerificacao == 0 && quantidadeJogadas < 9) {
        // Se for a vez do jogador
        if (jogadorAtual == 10) {
          printf("Sua vez (X)\n");
          // Loop para continuar perguntando se a jogada não for válida
          while (jogadaValida == 0) {
            printf("Digite uma posição\n");
            scanf("%d", &posicaoJogada);
            // Para o jogo se for digitado um número negativo
            if (posicaoJogada < 0) {
              printf("\nVocê teve %d vitórias\n", vitoriasJogador1);
              printf("O computador teve %d vitórias\n", vitoriasJogador2);
              printf("Aconteceram %d empates\n", empates);
              return 0;
            }
            // Verifica se a posição jogada é válida
            jogadaValida = VerificarJogada(matriz, posicaoJogada);
            // Se a jogada for válida, insere a jogada e aumenta a sua quantidade
            if (jogadaValida) {
              InserirJogada(matriz, posicaoJogada, jogadorAtual);
              quantidadeJogadas++;
            } else {
              printf("Essa posição já está ocupada!\n");
            }
          }
        }
        // Se for a vez do computador
        else {
          // Loop para continuar perguntando se a jogada não for válida
          while (jogadaValida == 0) {
            // Gera uma número aleatório de 1 a 9
            posicaoJogada = rand() % 9 + 1;
            // Verifica se a posição jogada é válida
            jogadaValida = VerificarJogada(matriz, posicaoJogada);
            // Se a jogada for válida, insere a jogada e aumenta a sua quantidade
            if (jogadaValida) {
              printf("O computador jogará (O):\n\n");
              InserirJogada(matriz, posicaoJogada, jogadorAtual);
              quantidadeJogadas++;
            }
          }
        }
        resultadoVerificacao = VerificarVitoria(matriz);
        // Inverte o jogador atual e reseta jogadaValida
        jogadorAtual = InverterJogador(jogadorAtual);
        jogadaValida = 0;
      }
      if (resultadoVerificacao == 1) {
        printf("O jogador 1 (X) ganhou!\n");
        vitoriasJogador1++;
        // Invertendo jogador para que o ganhador comece o próximo jogo
        jogadorAtual = InverterJogador(jogadorAtual);
      } else if (resultadoVerificacao == 2) {
        printf("O computador (O) ganhou\n");
        vitoriasJogador2++;
        // Invertendo jogador para que o ganhador comece o próximo jogo
        jogadorAtual = InverterJogador(jogadorAtual);
      } else {
        printf("O jogo deu empate\n");
        empates++;
      }
      // Resetando tabuleiro, resultadoVerificacao e quantidadeJogadas
      LimparTabuleiro(matriz);
      resultadoVerificacao = 0;
      quantidadeJogadas = 0;
      printf("\n\nNovo jogo começando\n");
      printf("Ou digite um número negativo para parar e ver resultados\n\n\n");
    }
  }

  return 0;
}