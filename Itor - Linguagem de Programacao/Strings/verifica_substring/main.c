#include <stdio.h>
#include <string.h>

int main() {

    char str1[20], str2[20];
    char *ptr;  // Armazenara a posicao em que a substring comeca

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    if (str1[strlen(str1) - 1] == '\n') {
        str1[strlen(str1) - 1] = '\0';
    }

    if (str2[strlen(str2) - 1] == '\n') {
        str2[strlen(str2) - 1] = '\0';
    }
    
    ptr = strstr(str1, str2);

    if (ptr == NULL) {
        printf("Substring nao econtrada!\n");
    } else {
        printf("%s\n", ptr);
    }

    return 0;
}