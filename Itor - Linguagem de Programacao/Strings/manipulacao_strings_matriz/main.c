#include <stdio.h>
#include <string.h>

#define LIM 5

int main() {

    char nomes[LIM][30];

    for (int i=0; i<LIM; i++) {

        fgets(nomes[i], sizeof(nomes[LIM]), stdin);
        int len = strlen(nomes[i]);
        
        if (nomes[i][len - 1] == '\n') {
            nomes[i][len - 1] ='\0';
        }
    }

    for (int i=LIM - 1; i>=0; i--) {
        if (i != 0) {
            printf("%s, ", nomes[i]);
        } else {
            printf("%s\n", nomes[i]);
        }
    }

    return 0;
}