#include <stdio.h>
#include <string.h>

int main() {

    char str[20];
    int len;

    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    if (str[len - 1] == '\n') {
        str[len - 1] == '\0';
        len--;
    }

    /**
     * é divido por 2 para que vá até o meio da string, faça na mão e verá que faz mais sentido
     * troca os chars iniciais [i] pelos ultimos [j]
     */
    for (int i=0, j=len-1; i<len/2; i++, j--) {
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }

    printf("%s\n", str);
    
    return 0;
}