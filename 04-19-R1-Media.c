// ---Código para praticar---

#include <stdio.h>

float calcmedia(int notas[3])
{
    int i = 0, soma = 0;
    float media;

    while (i < 3)
    {
        soma = soma + notas[i];
        i++;
    }

    media = (float)soma / 3;
    return media;
}

int main()
{
    int i = 0;
    int notas[3];

    while (i < 3)
    {
        printf("Digite o número %d: \n", i + 1);
        scanf("%d", &notas[i]);
        i++;
    }

    float media = calcmedia(notas);

    printf("%f\n", media);

    return 0;
}