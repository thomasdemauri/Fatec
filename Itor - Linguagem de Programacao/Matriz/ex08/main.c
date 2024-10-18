#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// ############ CONSTANTES 
#define LIN 5
#define COL 5
#define QTD_NAVIOS 2
#define VAZIO 0
#define NAVIO 1
#define NAVIO_ABATIDO 2
#define TIRO_ERRADO 3

// ############ CABECALHO DE FUNCOES 
void limpa_tabuleiro();
void instanciar_navios();
void desenha_tabuleiro();
void desenha_tiro_errado();
void desenha_navio_abatido();
void desenha_posicao_usada();
void desenha_vitoria();
void desenha_vidas();
void desenha_game_over();
void verifica_derrota_vitoria();
void processa_ataque(int pos_x, int pos_y);

// ############ VARIAVEIS 
int tabuleiro[LIN][COL];
int navios_abatidos = 0;
int vida = 5;
bool game_over = false;

int main() {

    limpa_tabuleiro();
    instanciar_navios();

    while (!game_over) {

        desenha_tabuleiro();

        int pos_x = 0, pos_y = 0;

        do {
            printf("Escolha a linha [1 - %d] => ", LIN);
            scanf("%d", &pos_x);
            getchar();
            printf("Escolha a coluna [1 - %d] => ", COL);
            scanf("%d", &pos_y);
            getchar();
            pos_x--;
            pos_y--;
        } while ((pos_x < 0 || pos_x > LIN - 1) || (pos_y < 0 || pos_y > COL - 1));

        processa_ataque(pos_x, pos_y);

        verifica_derrota_vitoria();
    }

    return 0;
}

void verifica_derrota_vitoria() {
    if (navios_abatidos == QTD_NAVIOS) {
        desenha_vitoria();
        game_over = true;
    }

    if (vida <= 0) {
        desenha_game_over();
        game_over = true;
    }

    return;
}

void processa_ataque(int pos_x, int pos_y) {

    switch (tabuleiro[pos_x][pos_y]) {
        case VAZIO:
            tabuleiro[pos_x][pos_y] = TIRO_ERRADO;
            vida--;
            desenha_tiro_errado();
            getchar();
            break;

        case NAVIO:
            tabuleiro[pos_x][pos_y] = NAVIO_ABATIDO;
            navios_abatidos++;
            desenha_navio_abatido();
            getchar();
            break;

        case NAVIO_ABATIDO:
            desenha_posicao_usada();
            vida--;
            getchar();
            break;

        case TIRO_ERRADO:
            desenha_posicao_usada();
            vida--;
            getchar();
            break;

        default:
            break;
    }

    return;
}

void desenha_game_over() {
    system("clear");
    printf("                      ###############               \n");
    printf("                        GAME OVER !!!              \n");
    printf("                      ##############               \n");
}

void desenha_vitoria() {
    system("clear");
    printf("     ____       \n");
    printf("    |    |      \n");
    printf("    |    |      \n");
    printf("    |____|      \n");
    printf("    |    |      \n");
    printf("    (    )      \n");
    printf("    )    (      \n");
    printf("  .'      `.    \n");
    printf("|------------|  \n");
    printf("|JACK DANIELS|  \n");
    printf("|    ----    |  \n");
    printf("|   (No.7)   | ------> VITORIA! <-------\n");
    printf("|    ----    |  \n");
    printf("| Tennessee  |  \n");
    printf("|  WHISKEY   |  \n");
    printf("|  40%% Vol.  |  \n");
    printf("|------------|  \n");
    printf("|____________|  \n");
    return;
}

void desenha_posicao_usada() {
    system("clear");
    printf("     ~~~~~~~ \n");
    printf("     ~ Oops! ~ \n");
    printf("     ~~~~~~~ \n");
    printf("  Você já atirou aqui! \n");
    return;
}

void desenha_navio_abatido() {
    system("clear");
    printf("    __|__ \n");
    printf("   |     | \n");
    printf("  /_______\\   \n");
    printf("  \\o o o o/  *BOOM* \n");
    printf("~~~~~~~~~~~~~ \n");
    return;
}

void desenha_tiro_errado() {
    system("clear");
    printf("     | \n");
    printf("     | \n");
    printf("  ~~~~~~~ \n");
    printf("  ~  SPLASH ~ \n");
    printf(" ~~~~~~~ \n");
    return;
}

void desenha_tabuleiro() {
    system("clear");

    for (int linha = 0; linha < LIN; linha++) {
        printf("[%d] ", linha+1);
        for (int coluna = 0; coluna < COL; coluna++) {
            switch (tabuleiro[linha][coluna]) {
            case VAZIO:
                printf(" - ");
                break;
            
            case NAVIO:
                printf(" - ");
                break;

            case NAVIO_ABATIDO:
                printf(" X ");
                break;

            case TIRO_ERRADO:
                printf(" O ");
                break;

            default:
                break;
            }
        }
        if (linha == 0) {
            printf("  ------- VIDA: ");
            desenha_vidas();
        }
        printf("\n");
    }
    return;
}

void desenha_vidas() {
    for (int i = 0; i < vida; i++) {
        printf(" ♥ ");
    }
}

void instanciar_navios() {

    srand(time(NULL));
    for (int navio = 0; navio < QTD_NAVIOS; navio++) {
        int pos_x = rand() % LIN;
        int pos_y = rand() % COL;
        if (tabuleiro[pos_x][pos_y] != NAVIO) {
            tabuleiro[pos_x][pos_y] = NAVIO; 
        } else {
            navio--;
        }
    }

    return;
}

void limpa_tabuleiro() {
    for (int linha = 0; linha < LIN; linha++) {
        for (int coluna = 0; coluna < COL; coluna++) {
            tabuleiro[linha][coluna] = VAZIO;
        }
    }
    return;
}