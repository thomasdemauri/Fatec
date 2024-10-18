#include <stdio.h>

#define ROW 3
#define COL 3

int main() {
	int m1[ROW][COL];
	int m2[ROW][COL];
    int different = 0;

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
			scanf("%d", &m1[i][j]);
		}
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
			scanf("%d", &m2[i][j]);
		}
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
            if (different) {
                break;
            }
            if (m1[i][j] != m2[i][j]) {
                different = 1;
            }
		}
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			printf("%d ", m1[i][j]);
		}

		printf("\n");
	}

    for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			printf("%d ", m2[i][j]);
		}

		printf("\n");
	}

    if (different) {
        printf("AS MATRIZES NAO SAO IDENTICAS!\n");
    } else {
        printf("AS MATRIZES SAO IDENTICAS!\n");
    }

    return 0;
}
