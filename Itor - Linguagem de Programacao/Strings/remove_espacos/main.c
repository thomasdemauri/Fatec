#include <stdio.h>
#include <string.h>

int main() {

    int len;
    char str[50];

    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    if (str[len - 1] == '\n') {
        str[len - 1] == '\0';
        len--;
    }

    /**
     * Quando encontra um espaco em branco na posicao i
     * vai da posicao i ate o final realocando os caracteres na posicao - 1
     * porque o espaco foi tirado
     */
    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            for (int j=i; j < len; j++) {
                str[j] = str[j + 1]; 
            }
        }
    }

    printf("%d\n", len);
    printf("%s\n", str);

    return 0;
}