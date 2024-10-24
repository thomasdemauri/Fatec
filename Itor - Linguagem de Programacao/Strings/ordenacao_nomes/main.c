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

    for (int j=0; j<LIM; j++) {
        for (int i=0; i<LIM - 1; i++) {
            if (strcmp(nomes[i], nomes[i + 1]) > 0) {
                // string i+1 vem antes
                char aux[30];
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[i + 1]);
                strcpy(nomes[i + 1], aux); 
            }
        }
    }

    for (int i=0; i<LIM; i++) {
        printf("%s ", nomes[i]);
    }

    return 0;
}