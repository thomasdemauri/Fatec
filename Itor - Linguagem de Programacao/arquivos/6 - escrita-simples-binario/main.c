#include <stdio.h>


int main() {

    int numbers[5];
    FILE *file = fopen("numeros.bin", "wb");

    scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);

    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    fwrite(numbers, sizeof(int), 5, file);
    
    fclose(file);

    return 0;
}