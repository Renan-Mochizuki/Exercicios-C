// ---Instruções da atividade---
// 1. Apresente um algoritmo (português estruturado) ou uma função em C que tenha como entrada um número
// real que indique uma temperatura em graus Celsius e retorne o valor dessa temperatura em graus Fahrenheit 

#include <stdio.h>

float ConverterParaFahrenheit(float celsius){
  float fahrenheit;
  fahrenheit = (celsius * 9 + 160)/5;
  return fahrenheit;
}

int main(void) {
  float celsius, fahrenheit;
  
  printf("Insira uma temperatura em Celsius:\n");
  scanf("%f", &celsius);

  fahrenheit = ConverterParaFahrenheit(celsius);

  printf("A temperatura em Fahrenheit é: %.2f", fahrenheit);
  
  return 0;
}