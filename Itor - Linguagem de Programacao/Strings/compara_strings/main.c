#include <stdio.h>
#include <string.h>

int main() {

    char str1[50], str2[50];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    int cmp = strcmp(str1, str2);

    if (cmp == 0) {
        printf("As strings sao iguais!\n");
    } else if (cmp == 1) {
        printf("A string 2 vem antes!\n");
    } else {
        printf("A string 1 vem antes!\n");
    }

    return 0;
}