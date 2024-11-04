#include <stdio.h>
#include <string.h>

typedef struct 
{
    char  nome[30];
    int   idade;
    float altura;
} Pessoa;

int main() {

    Pessoa p1;

    printf("Nome: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);
    strtok(p1.nome, "\n");
    printf("Idade: ");
    scanf("%d", &p1.idade);
    printf("Altura: ");
    scanf("%f", &p1.altura);

    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Altura: %.2f\n", p1.altura);
    printf("Maior de idade: ");
    (p1.idade > 18) ? printf("Sim\n") : printf("Nao\n");
}