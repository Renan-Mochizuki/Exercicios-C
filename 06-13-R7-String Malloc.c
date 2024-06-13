// ---Código para praticar---

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Alocando memória para um char de n letras
    int n = 5;
    char *pvowels = malloc(n * sizeof(char));

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    pvowels[2] = 'I';
    // Ou:
    *(pvowels + 3) = 'O';
    *(pvowels + 4) = 'U';

    for (int i = 0; i < n; i++)
    {
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    free(pvowels);

    printf("\n");

    // Alocando memória para uma matriz de n linhas e m colunas
    int nlinhas = 2;
    int mcolunas = 5;

    // Alocando memória para ponteiros de n linhas
    char **pvowel = malloc(nlinhas * sizeof(char *));

    // Alocando memória de mcolunas para cada linha
    for (int i = 0; i < nlinhas; i++)
    {
        pvowel[i] = malloc(mcolunas * sizeof(char));
    }

    pvowel[0][0] = 'A';
    pvowel[0][1] = 'E';
    pvowel[0][2] = 'I';
    pvowel[0][3] = 'O';
    pvowel[0][4] = 'U';

    pvowel[1][0] = 'a';
    pvowel[1][1] = 'e';
    pvowel[1][2] = 'i';
    pvowel[1][3] = 'o';
    pvowel[1][4] = 'u';

    // Loop que percorre toda a matriz
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < mcolunas; j++)
        {
            printf("%c ", pvowel[i][j]);
        }

        printf("\n");
    }

    // Limpando memória de cada linha
    for (int i = 0; i < nlinhas; i++)
    {
        free(pvowel[i]);
    }

    free(pvowel);

    return 0;
}