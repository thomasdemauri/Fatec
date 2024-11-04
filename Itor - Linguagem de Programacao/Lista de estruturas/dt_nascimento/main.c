#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


typedef struct {
    char nome[30];
    Data nascimento;
    int idade;
} Pessoa;

int main() {

    int ano_base = 2024;
    Pessoa p1;
    char *token;

    printf("Nome: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);
    strtok(p1.nome, "\n");

    printf("Data nascimento: ");
    char nasc[30];
    fgets(nasc, sizeof(nasc), stdin);
    strtok(nasc, "\n");

    token = strtok(nasc, "/");

    int index_token = 0;
    while (token != NULL) {

        if (index_token == 0) {
            p1.nascimento.dia = atoi(token);
        }
        if (index_token == 1) {
            p1.nascimento.mes = atoi(token);
        }
        if (index_token == 2) {
            p1.nascimento.ano = atoi(token);
        }

        token = strtok(NULL, "/");
        index_token++;
    }

    p1.idade = ano_base - p1.nascimento.ano;

    printf("Nome: %s\n", p1.nome);
    printf("Data de nascimento: %02d/%02d/%d\n", p1.nascimento.dia, p1.nascimento.mes, p1.nascimento.ano);
    printf("Idade: %d\n", p1.idade);

    return 0;
}