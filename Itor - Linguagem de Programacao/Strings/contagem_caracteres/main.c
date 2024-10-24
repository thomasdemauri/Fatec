#include <stdio.h>
#include <string.h>

int main() {

    int len, i = 0;
    char str[50];

    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
        i++;
    }

    len = strlen(str);

    printf("%d\n", len);

    return 0;
}