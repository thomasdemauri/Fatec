#include <stdio.h>

int main() {

	int matriz[3][3], soma=0;

	for(int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			matriz[i][j] = i * j;
		}
	}

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			soma+=matriz[i][j];
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("Soma: %d\n", soma);

	return 0;
}
