#include <stdio.h>

#define ABERTO 'o'
#define FECHADO 'c'
#define MAX_ANDARES 100
#define APTOS 4         // Máximo de apartamentos por andar

void boot(int *n_andares, int *n_chaves);
void popula_chaves(int *chaves, int len);
void boot_aptos(int predio[][APTOS], int portas[][APTOS], int len);
void verifica_portas(int predio[][APTOS], int portas[][APTOS], int len, int *chaves, int len_chaves);
char altera_estado(char estado);

/**
 * A é número de andares do prédio
 * N é a quantidade de números, vamos chama-los de chaves
 *
 * Cada andar tem sempre 4 apartamentos
 * Cada apartamento é (A * 10) + apartamento atual [0 - 1]
 *
 * N[i] deve passar por todos apartamentos e comparar se apartamento % N[i] == 0
 * Se o apartamento for múltiplo, abrir a porta
 */


int main() {

    int n_andares = 0;  // Número de andares do prédio
    int n_chaves = 0;   // Número de chaves

    boot(&n_andares, &n_chaves);

    int chaves[n_chaves];
    int predio[n_andares][APTOS];
    int portas[n_andares][APTOS];

    // Usuario entra com os números desejados para N
    popula_chaves(chaves, n_chaves);

    // Cria os números dos apartamentos e fecha todas as portas
    boot_aptos(predio, portas, n_andares);

    // Percorre cada apartamento do prédio verificando conforme instrução
    verifica_portas(predio, portas, n_andares, chaves, n_chaves);

    return 0;
}

char altera_estado(char estado) {

    if (estado == FECHADO) {
        return ABERTO;
    }

    return FECHADO;
}

void verifica_portas(int predio[][APTOS], int portas[][APTOS], int len, int *chaves, int len_chaves) {

    for (int numero=0; numero<len_chaves; numero++) {
        for (int andar=0; andar<len; andar++) {
            for (int apto=0; apto<APTOS; apto++) {

                if (predio[andar][apto] % chaves[numero] == 0) {
                    portas[andar][apto] = altera_estado(portas[andar][apto]);
                }

            }
        }
    }

    for (int andar=0; andar<len; andar++) {
        printf("Andar %d: ", andar+1);
        for (int apto=0; apto<APTOS; apto++) {
            printf("%c ", portas[andar][apto]);
        }
        printf("\n");
    }

    return;
}

void boot_aptos(int predio[][APTOS], int portas[][APTOS], int len) {

    for (int andar=0; andar<len; andar++) {
        for (int apto=0; apto<APTOS; apto++) {
            predio[andar][apto] = ((andar+1) * 10) + (apto+1);
            portas[andar][apto] = FECHADO;
        }
    }

    return;
}

void popula_chaves(int *chaves, int len) {

    for (int i=0; i<len; i++) {
        do {
            scanf("%d", &chaves[i]);
        } while (chaves[i] < 1);
    }

    return;
}

void boot(int *n_andares, int *n_chaves) {

    do {
        scanf("%d %d", n_andares, n_chaves);
    } while (*n_andares < 1 || *n_andares > MAX_ANDARES || *n_chaves < 1);

    return;
}
