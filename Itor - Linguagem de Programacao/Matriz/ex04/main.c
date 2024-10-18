// MIN E MAX MATRIZ

#include <stdio.h>

#define ROW 3
#define COL 3

int main() {

	int matriz[ROW][COL];

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			matriz[i][j] = 4 * (i+1) * (j * 2);
		}
	}

	int min = matriz[0][0], max = matriz[0][0];
	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			if (matriz[i][j] > max) {
				max = matriz[i][j];
			}

			if (matriz[i][j] < min) {
				min = matriz[i][j];
			}
		}
	}

	for (int i=0; i<ROW; i++) {
		for (int j=0; j<COL; j++) {
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}

	printf("MAIOR: %d\n", max);
	printf("MENOR: %d\n", min);
	return 0;
}
