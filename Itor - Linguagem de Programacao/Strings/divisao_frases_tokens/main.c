#include <stdio.h>
#include <string.h>

int main() {

    int index = 0;
    char str[256], tokens[20][30];
    char *token;

    fgets(str, sizeof(str), stdin);

    /**
     * Obtem o primeiro token e o ponteiro fica armazenado
     */
    token = strtok(str, " ");

    while (token != NULL) {
        // Copia entao o token para o array de tokens
        strcpy(tokens[index++], token); 
        // Posiciona ponteiro para o proximo token 
        token = strtok(NULL, " ");
    }

    for (int i=0; i<index; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}