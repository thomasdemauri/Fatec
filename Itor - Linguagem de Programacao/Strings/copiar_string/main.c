#include <stdio.h>
#include <string.h>

int main() {

    char str[20], copy[20];
    fgets(str, sizeof(str), stdin);

    strcpy(copy, str);

    printf("%s\n", copy);

    return 0;
}