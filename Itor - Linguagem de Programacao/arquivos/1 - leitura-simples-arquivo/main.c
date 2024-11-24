#include <stdio.h>

#define FILENAME "mensagem.txt"

int main() {

    char buffer[100];

    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    fgets(buffer, sizeof(buffer), file);

    printf("%s\n", buffer);

    return 0;
}