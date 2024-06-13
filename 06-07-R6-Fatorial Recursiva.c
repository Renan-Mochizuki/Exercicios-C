// ---Código para praticar---

#include <stdio.h>

int fatorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * fatorial(x - 1);
    }
}

int main()
{
    printf("0! = %i\n", fatorial(0));
    printf("1! = %i\n", fatorial(1));
    printf("3! = %i\n", fatorial(3));
    printf("5! = %i\n", fatorial(5));
    printf("10! = %i\n", fatorial(10));
}