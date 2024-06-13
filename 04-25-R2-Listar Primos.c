// ---Código para praticar---

#include <stdio.h>

int verificarSeEPrimo(int num)
{

    int i = 2;
    while (i <= num / 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    int limite;
    int numeroAtual = 1;

    printf("Progama listar números primos\n");
    printf("Digite o limite:\n");
    scanf("%d", &limite);

    printf("Os números primos são:\n");

    while (numeroAtual <= limite)
    {

        if (verificarSeEPrimo(numeroAtual))
        {
            printf("%d, ", numeroAtual);
        }
        numeroAtual++;
    }
    return 0;
}