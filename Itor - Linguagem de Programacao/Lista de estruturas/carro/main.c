#include <stdio.h>
#include <string.h>

typedef struct {
    char modelo[30];
    int  ano_fab;
    int  km_rodado;
    int  idade;
} Carro;

int main() {

    int const ano_atual = 2024;
    Carro carro;

    printf("Modelo: ");
    fgets(carro.modelo, sizeof(carro.modelo), stdin);
    strtok(carro.modelo, "\n");


    printf("Quilometragem: ");
    scanf("%d", &carro.km_rodado);

    printf("Ano de fabricacao: ");
    scanf("%d", &carro.ano_fab);

    carro.idade = ano_atual - carro.ano_fab;

    printf("Modelo: %s\n", carro.modelo);
    printf("Quilometragem: %d\n", carro.km_rodado);
    printf("Ano de fabricacao: %d\n", carro.ano_fab);
    printf("Idade do carro: %d anos\n", carro.idade);

    return 0;
}