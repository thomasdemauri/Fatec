// MATRIZ QUE EXIBA APENAS A BORDA

#include <stdio.h>

#define ROW 3
#define COL 3

int main() {
	int matriz[ROW][COL];

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL;  j++) {
			matriz[i][j] = 3 * (i+1) * (j+1);
		}
	}

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}

	printf("SOMENTE AS BORDAS ==> \n");

	for (int i=0; i<ROW; i++) {
		for (int  j=0; j<COL; j++) {
			if ((j == 0 || j == COL - 1) || (i == 0 || i == ROW -1)) {
				printf("%d ", matriz[i][j]);
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
