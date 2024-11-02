#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VIAGENS 2
#define MAX_CHAR 64
#define MAX_FROTA 3

typedef struct {
    int id;
    float distancia;
    char destino[MAX_CHAR];
} Voo;

typedef struct {
    char id[MAX_CHAR];
    float total_percorrido;
    Voo viagens[MAX_VIAGENS];
} Aviao;

void exibe_voo(int indice_aviao, int indice_viagem);
void exibe_cabecalho_relatorio_por_aviao(int indice_aviao);
void exibe_todos_voos();
void exibe_maior_e_menor_voo();

void trata_entrada_string(char *str);
void ordena_por_total_percorrido();
void calcula_total_percorrido_por_aviao();
void calcula_maior_e_menor_voo(int *i_maior_aviao, int *i_maior_viagem, int *i_menor_aviao, int *i_menor_viagem);

Aviao frota[MAX_FROTA];
int id_voo = 1053;                          // Número aleatório para simular o ID de cada voo.   
int i_maior_aviao, i_menor_aviao;           // Índice no array de aviões. 
int i_maior_viagem, i_menor_viagem;         // índice no array de viagens do avião.


int main() {

    bool sair = false;

    system("clear");
    printf("GERENCIAMENTO DE AVIOES E VOOS\n");

    for (int aviao=0; aviao<MAX_FROTA; aviao++) {
        system("clear");
        printf("MODELO: ");
        fgets(frota[aviao].id, sizeof(frota[aviao].id), stdin);
        trata_entrada_string(frota[aviao].id);

        for (int viagem=0; viagem<MAX_VIAGENS; viagem++) {
            frota[aviao].viagens[viagem].id = ++id_voo;
            printf("ID VOO: %d\n", frota[aviao].viagens[viagem].id);
            printf("DESTINO: ");
            fgets(frota[aviao].viagens[viagem].destino, sizeof(frota[aviao].viagens[viagem].destino), stdin);
            trata_entrada_string(frota[aviao].viagens[viagem].destino);
            printf("DISTANCIA: ");
            scanf("%f", &frota[aviao].viagens[viagem].distancia);
            getchar();      // Limpa o buffer.
            printf("\n");
        }
    }

    // Realiza todos os calculos necessários.
    calcula_total_percorrido_por_aviao();
    ordena_por_total_percorrido();
    calcula_maior_e_menor_voo(&i_maior_aviao, &i_maior_viagem, &i_menor_aviao, &i_menor_viagem);

    // Exibe os relatórios.
    exibe_todos_voos();
    exibe_maior_e_menor_voo();

    return 0;
}

void calcula_maior_e_menor_voo(int *i_maior_aviao, int *i_maior_viagem, int *i_menor_aviao, int *i_menor_viagem) {
    // Recebe os índices no array de avião e do voo.
    int maior = frota[0].viagens[0].distancia, menor = frota[0].viagens[0].distancia;
    for (int aviao=0; aviao<MAX_FROTA; aviao++) {
        for (int viagem=0; viagem<MAX_VIAGENS; viagem++) {
            // Maior
            if (frota[aviao].viagens[viagem].distancia > maior) {
                maior = frota[aviao].viagens[viagem].distancia;
                *i_maior_aviao = aviao;
                *i_maior_viagem = viagem;
            }
            // Menor
            if (frota[aviao].viagens[viagem].distancia < menor) {
                menor = frota[aviao].viagens[viagem].distancia;
                *i_menor_aviao = aviao;
                *i_menor_viagem = viagem;
            }
        }
    }
    return;
}

void calcula_total_percorrido_por_aviao() {
    // Calcula a distância total percorrida contabilizando a distância de cada voo.
    for (int aviao=0; aviao<MAX_FROTA; aviao++) {
        frota[aviao].total_percorrido = 0;
        for (int viagem=0; viagem<MAX_VIAGENS; viagem++) {
            frota[aviao].total_percorrido += frota[aviao].viagens[viagem].distancia;
        }
    }
    return;
}

void ordena_por_total_percorrido() {
    // Bubble sort para ordenar em ordem decrescente o total percorrido dos voos.
    for (int i=0; i<MAX_FROTA; i++) {
        for (int aviao=0; aviao<MAX_FROTA-i-1; aviao++) {
            if (frota[aviao].total_percorrido > frota[aviao+1].total_percorrido) {
                Aviao tmp_aviao = frota[aviao];
                frota[aviao]    = frota[aviao+1];
                frota[aviao+1]  = tmp_aviao;
            }
        }
    }
    return;
}

void exibe_maior_e_menor_voo() {
    printf("\nMAIOR VOO: \n");
    exibe_cabecalho_relatorio_por_aviao(i_maior_aviao);
    exibe_voo(i_maior_aviao, i_maior_viagem);
    printf("\nMENOR VOO: \n");
    exibe_cabecalho_relatorio_por_aviao(i_menor_aviao);
    exibe_voo(i_menor_aviao, i_menor_viagem);
    return;
}

void exibe_todos_voos() {
    // Exibe o relatório.
    for (int aviao=0; aviao<MAX_FROTA; aviao++) {
        exibe_cabecalho_relatorio_por_aviao(aviao);
        for (int viagem=0; viagem<MAX_VIAGENS; viagem++) {
            exibe_voo(aviao, viagem);
        }
        printf("\n");
    }
    return;
}

void exibe_cabecalho_relatorio_por_aviao(int indice_aviao) {
    printf("==========================================================================================================================\n");
    printf("ID: %-32s TOTAL PERCORRIDO: %-32.2f\n", frota[indice_aviao].id, frota[indice_aviao].total_percorrido);
    return;
}

void exibe_voo(int indice_aviao, int indice_viagem) {
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tVOO: %-32d DISTANCIA: %-32.2f DESTINO: %-32s\n",
        frota[indice_aviao].viagens[indice_viagem].id, frota[indice_aviao].viagens[indice_viagem].distancia, 
        frota[indice_aviao].viagens[indice_viagem].destino);
    return;
}

void trata_entrada_string(char *str) {

    int length = strlen(str);

    if (str[length-1] == '\n') {
        str[length-1] = '\0';
    }

    return;
}
