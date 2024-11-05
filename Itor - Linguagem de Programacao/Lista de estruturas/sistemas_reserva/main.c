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
    char quarto[10];
    Data check_in;
    Data check_out;  
    int  duracao;  
} Reserva;

int diff(Data check_in, Data check_out);
void cadastra(Reserva *reserva);
void tok_data(char *str, Data *data);
void imprime_reservas(Reserva *reservas);

int main() {

    Reserva reservas[3];

    for (int i=0; i<3; i++) {
        cadastra(&reservas[i]);
    }

    imprime_reservas(reservas);

    return 0;
}

void imprime_reservas(Reserva *reservas) {
    for (int i=0; i<3; i++) {
        printf("Reserva %d: Nome: %s, Quarto: %s, Check-in: %02d/%02d/%04d, Check-out: %02d/%02d/%04d, periodo: %d dias.\n", 
            (i+1), reservas[i].nome, reservas[i].quarto, 
            reservas[i].check_in.dia, reservas[i].check_in.mes, reservas[i].check_in.ano,
            reservas[i].check_out.dia, reservas[i].check_out.mes, reservas[i].check_out.ano, reservas[i].duracao);
    }
    return;
}

void cadastra(Reserva *reserva) {
    char check_in[15], check_out[15];

    printf("NOME: ");
    fgets(reserva->nome, sizeof(reserva->nome), stdin);
    strtok(reserva->nome, "\n");

    printf("N. QUARTO: ");
    fgets(reserva->quarto, sizeof(reserva->quarto), stdin);
    strtok(reserva->quarto, "\n");

    printf("CHECK IN: ");
    fgets(check_in, sizeof(check_in), stdin);
    strtok(check_in, "\n");

    printf("CHECK OUT: ");
    fgets(check_out, sizeof(check_out), stdin);
    strtok(check_out, "\n");

    tok_data(check_in, &reserva->check_in);
    tok_data(check_out, &reserva->check_out);
    
    reserva->duracao = diff(reserva->check_in, reserva->check_out);

    return;
}

int diff(Data check_in, Data check_out) {
    /**
     * Nao esta calculando quando existe diferenca entre anos.
     */
    int data_1 = (check_in.mes * 31) + check_in.dia;
    int data_2 = (check_out.mes * 31) + check_out.dia;
    
    return data_2 - data_1;
}

void tok_data(char *str, Data *data) {

    int index_token = 0;
    char *token;

    token = strtok(str, "/");

    while (token != NULL) {

        if (index_token == 0) {
            data->dia = atoi(token);
        }
        if (index_token == 1) {
            data->mes = atoi(token);
        }
        if (index_token == 2) {
            data->ano = atoi(token);
        }

        token = strtok(NULL, "/");
        index_token++;
    }

    return;
}