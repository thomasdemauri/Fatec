#include <stdio.h>
#include <string.h>

int main() {

    char str1[20], str2[20];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    if (str1[strlen(str1) - 1] == '\n') {
        str1[strlen(str1) - 1] = '\0';
    }

    if (str2[strlen(str2) - 1] == '\n') {
        str2[strlen(str2) - 1] = '\0';
    }
    
    printf("%s\n", strcat(str1, str2));

    return 0;
}