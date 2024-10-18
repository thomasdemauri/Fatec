#include <stdio.h>

#define ROW 3
#define COL 3

void print_matriz(int matriz[ROW][COL]);
void sort_1(int matriz[ROW][COL]);
void sort_2(int matriz[ROW][COL]);
void bubble_sort(int *array, int len);

int main() {

    int matriz[ROW][COL] = {
        {21, 7, 5},
        {6, 4, 2},
        {8, 3, 1},
    };

    // sort_1(matriz);
    sort_2(matriz);

    print_matriz(matriz);

    return 0;
}

void bubble_sort(int *array, int len) {

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (j + 1 < len) {
                if (array[j] > array[j + 1]) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }

    return;
}

/**
 * Ja esse metodo por sua vez transforma uma matriz para um simples array,
 * aplica do metodo bubble_sort e entao coloca os valores ordenados
 * de volta para a matriz.
 */
void sort_2(int matriz[ROW][COL]) {

    int len = ROW * COL;
    int array[len];
    int k = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            array[k] = matriz[i][j];
            k++;
        }
    }

    bubble_sort(array, len);

    k = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matriz[i][j] = array[k];
            k++;
        }
    }

    // for (int i = 0; i < len; i++) {
    //     printf("%d ", array[i]);
    // }
}

/**
 * CONSIDERAÇÕES
 * 
 * Me surpreendi por ter dado certo dessa forma, pois a comparação está sendo feita
 * entre os vizinhos da mesma linha. Em determinado momento, todos em sua própria linha
 * estarão ordenados, mas não garante que a linha que antecede tenha somente números menores
 * 
 * Seria então necessário uma comparação entre linhas também, por exemplo: matriz[2][2], comparar 
 * matriz[0][1] > matriz[1][0] ? Final da linha 1 com comeco da linha 2.
 * 
 * No entanto, acredito que tenha dado certo por conta do funcionamento por debaixo dos capô
 * das matrizes, pois na memória os endereços são sempre subsequentes, 
 * logo quando comparo j + 1 no final de cada linha, é simplesmente acessado o proximo endereco 
 * que consequentemente e a linha debaixo, apesar de estar fora dos limites na teoria.
 */
void sort_1(int matriz[ROW][COL]) {
    for (int k = ROW*COL; k >= 0; k--) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (matriz[i][j] > matriz[i][j + 1]) {
                    int tmp = matriz[i][j];
                    matriz[i][j] = matriz[i][j + 1];
                    matriz[i][j + 1] = tmp; 
                }
            }
        }
    }
}

void print_matriz(int matriz[ROW][COL]) {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}