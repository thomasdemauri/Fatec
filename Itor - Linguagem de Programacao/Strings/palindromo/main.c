#include <stdio.h>
#include <string.h>

int main() {

    char str[20], str_check[20];
    int len;

    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    if (str[len - 1] == '\n') {
        str[len - 1] == '\0';
        len--;
    }

    strcpy(str_check, str);

    /**
     * é divido por 2 para que vá até o meio da string, faça na mão e verá que faz mais sentido
     * troca os chars iniciais [i] pelos ultimos [j]
     */
    for (int i=0, j=len-1; i<len/2; i++, j--) {
        char aux = str_check[i];
        str_check[i] = str_check[j];
        str_check[j] = aux;
    }

    if (strcmp(str, str_check) == 0) {
        printf("Sim.\n");
    } else {
        printf("Nao.\n");
    }
    
    return 0;
}