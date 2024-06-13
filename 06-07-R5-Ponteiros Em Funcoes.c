// ---Código para praticar---

#include <stdio.h>

typedef struct
{
    char *nome;
    int idade;
} pessoa;

void AumentarIdade(pessoa *p)
{
    // Como P é um ponteiro devemos usar a seta em vez do ponto
    p->idade++;
    // Ou então:
    (*p).idade++;
}

int main()
{
    pessoa cliente1;
    cliente1.nome = "John";
    cliente1.idade = 27;

    printf("%s tem %d anos.\n", cliente1.nome, cliente1.idade);

    AumentarIdade(&cliente1);

    printf("%s agora tem %d anos.\n", cliente1.nome, cliente1.idade);

    return 0;
}