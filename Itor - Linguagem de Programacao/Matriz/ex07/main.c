#include <stdio.h>

#define ROW 3
#define COL 3

int main() {
	int matriz[ROW][COL];
    int different = 0;

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
			scanf("%d", &matriz[i][j]);
		}
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
            if (matriz[i][j] != matriz[j][i]) {
                different = 1;
            }
		}
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

    if (different) {
        printf("AS MATRIZES NAO SAO SIMETRICAS!\n");
    } else {
        printf("AS MATRIZES SAO SIMETRICAS!\n");
    }

    return 0;
}
