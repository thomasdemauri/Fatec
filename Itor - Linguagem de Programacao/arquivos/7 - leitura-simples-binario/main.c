#include <stdio.h>


int main() {

    int numbers[5];
    FILE *file = fopen("numeros.bin", "rb");

    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    fread(numbers, sizeof(int), 5, file);

    for (int i=0; i<5; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
    
    fclose(file);

    return 0;
}