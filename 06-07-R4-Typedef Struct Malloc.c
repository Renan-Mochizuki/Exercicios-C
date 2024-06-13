// ---Código para praticar---

#include <stdio.h>
#include <stdlib.h>

// Definindo struct com o nome estrutura e dados int x e char y
typedef struct
{
    int x;
    char *y;
} estrutura;

int main()
{
    // Criando variável mypoint como sendo um ponteiro da estrutura e NULL
    estrutura *mypoint = NULL;
    // Alocando memória para mypoint
    mypoint = (estrutura *)malloc(sizeof(estrutura));

    // Ou simplesmente:
    estrutura *mypoint2 = malloc(sizeof(estrutura));

    // Acessar valores da alocação
    mypoint->x = 10;
    mypoint->y = "Cinco";
    printf("Variáveis da mypoint: %d, %s\n", mypoint->x, mypoint->y);

    // Limpar memória do mypoint
    free(mypoint);
    free(mypoint2);

    return 0;
}