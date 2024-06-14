// ---Código para praticar---

#include <stdio.h>
#include <stdlib.h>

void PreencherPascal(int **triangulo, int alturaDoTriangulo)
{
    // Loop que percorre as linhas do triângulo
    for (int linha = 0; linha < alturaDoTriangulo; linha++)
    {
        // Atribuindo o primeiro valor como 1
        triangulo[linha][0] = 1;
        // Loop que preencherá as casas do meio
        for (int casa = 1; casa < linha; casa++)
        {
            // Some as duas casas de cima
            triangulo[linha][casa] = triangulo[linha - 1][casa - 1] + triangulo[linha - 1][casa];
        }
        // Definindo o último valor como 1
        triangulo[linha][linha] = 1;
    }
}

int main(void)
{
    int alturaDoTriangulo;

    printf("Digite a altura do triangulo de Pascal:\n");
    scanf("%d", &alturaDoTriangulo);

    // Declare uma matriz alocando memória da altura do triângulo
    int **triangulo = malloc(alturaDoTriangulo * sizeof(int *));

    // Loop que alocará memória para cada item da matriz
    for (int i = 0; i < alturaDoTriangulo; i++)
    {
        // Alocando memória de maneira crescente para cada item
        triangulo[i] = malloc((i + 1) * sizeof(int));
    }

    PreencherPascal(triangulo, alturaDoTriangulo);

    printf("\n");

    // Loop que imprime o triângulo de Pascal, percorrendo cada linha
    for (int i = 0; i < alturaDoTriangulo; i++)
    {
        // Loop que percorre toda essa linha
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", triangulo[i][j]);
        }
        printf("\n");
    }

    // Loop para liberar a memória alocada
    for (int i = 0; i < alturaDoTriangulo; i++)
    {
        free(triangulo[i]);
    }
    free(triangulo);

    return 0;
}