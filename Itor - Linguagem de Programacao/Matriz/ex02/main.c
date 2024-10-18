// MATRIZ (3X2) E RETORNE A TRANSPOSTA;

#include <stdio.h>

#define ROW 3
#define COL 2

int main() {

	int matriz[ROW][COL];

	for (int i=0; i<ROW; i++) {
		scanf("%d %d", &matriz[i][0], &matriz[i][1]); // APENAS POR QUESTOES DE SIMPLIFICACAO A COLUNA ESTA HARDCODE
	}

	for (int i=0; i<COL; i++) {
		for (int j=0; j<ROW; j++) {
			printf("%d ", matriz[j][i]);
		}
		printf("\n");
	}

	return 0;
}
