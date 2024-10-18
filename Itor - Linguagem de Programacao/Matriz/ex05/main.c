#include <stdio.h>

#define ROW 2
#define COL 2

void print_matriz(int matriz[ROW][COL]) {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

    /**
     * CONSIDERAÇÕES
     * 
     * O memso índice da linha m1 será igual o índice da coluna m2 para multiplicar,
     * exemplo: índice 1 da linha m1 estará multiplicando o índice 1 da coluna m2, e assim sucessivamente...
     * 
     * 1o da linha pelo 1o da coluna, 2o da linha pelo 2o da coluna... 
     * 
     * Então, o 3o loop é responsável por ser esse índice que dá "match" em m1 e m2 para que seja possível 
     * realizar a multiplicação.
     * 
     * i é necessário para que percorra a quantidade de linhas da matriz
     * j é necessário para que ele percorra a quantidade de linhas da coluna, mas note que 
     * Note que fica [k][j] na m2, onde k ira percorrer os mesmo índices da m1, no tanto que colunas que tiver m2  
     *    
     */

    int m1[ROW][COL] = {{1, 2}, {3, 4}};
    int m2[ROW][COL] = {{2, 0}, {1, 2}};

    int res[ROW][COL] = {{0, 0}, {0, 0}};

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < COL; k++) {
                // printf("%d x %d = %d | ", m1[i][k], m2[k][j], m1[i][k]*m2[k][j]);
                res[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }

    print_matriz(res);

    return 0;
}