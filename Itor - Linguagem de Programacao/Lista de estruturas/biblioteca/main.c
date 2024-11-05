#include <stdio.h>
#include <string.h>

#define MAX_CHARS 64
#define MAX_LIVROS 3

typedef struct {
    char titulo[MAX_CHARS];
    char autor[MAX_CHARS];
    char ano_pub[MAX_CHARS];    // ja que nao tem calculo, coloquei como char mesmo
} Livro;

int main() {

    Livro livros[MAX_LIVROS];

    for (int i=0; i<MAX_LIVROS; i++) {
        printf("Livro [%d]\n", i+1);
        printf("Titulo: ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        strtok(livros[i].titulo, "\n");

        printf("Autor: ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        strtok(livros[i].autor, "\n");

        printf("Ano publicacao: ");
        fgets(livros[i].ano_pub, sizeof(livros[i].ano_pub), stdin);
        strtok(livros[i].ano_pub, "\n");
    }

    for (int i=0; i<MAX_LIVROS; i++) {
        for (int j=0; j < MAX_LIVROS-i-1; j++) {
            if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
                Livro tmp = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = tmp;
            }
        }
    }

    for (int i=0; i<MAX_LIVROS; i++) {
        printf("TITULO: %s, AUTOR: %s, ANO PUB: %s\n", livros[i].titulo, livros[i].autor, livros[i].ano_pub);
    }

    return 0;
}