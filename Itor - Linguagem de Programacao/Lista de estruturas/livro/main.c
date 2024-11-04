#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[30];
    char autor[30];
    int  ano_pub;
    int  idade;
} Livro;

int main() {

    int const ano_atual = 2024;
    Livro l1;

    printf("Titulo: ");
    fgets(l1.titulo, sizeof(l1.titulo), stdin);
    strtok(l1.titulo, "\n");

    printf("Autor: ");
    fgets(l1.autor, sizeof(l1.autor), stdin);
    strtok(l1.autor, "\n");

    printf("Ano de publicacao: ");
    scanf("%d", &l1.ano_pub);

    l1.idade = ano_atual - l1.ano_pub;

    printf("Titulo: %s\n", l1.titulo);
    printf("Autor: %s\n", l1.autor);
    printf("Ano de publicacao: %d\n", l1.ano_pub);
    printf("Idade do livro: %d anos\n", l1.idade);

    return 0;
}