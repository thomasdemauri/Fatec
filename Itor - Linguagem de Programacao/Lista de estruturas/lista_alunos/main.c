#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3
#define MAX_NOTAS 3

typedef struct {
    char nome[30];
    float notas[MAX_NOTAS];
    float media;
} Aluno;

void cria_alunos(Aluno *alunos) {
    for (int i=0; i<MAX_ALUNOS; i++) {
        printf("Aluno: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        strtok(alunos[i].nome, "\n");

        for (int j=0; j<MAX_NOTAS; j++) {
            printf("Nota [%d]: ", j+1);
            scanf("%f", &alunos[i].notas[j]);
            getchar();  // Clear the buffer
        }
    }
}

float calcula_media(Aluno *aluno) {
    float acc = 0;
    for (int i=0; i<MAX_NOTAS; i++) {
        acc += aluno->notas[i];
    }
    return acc / MAX_NOTAS;
}

void fechamento_media_alunos(Aluno *alunos) {
    for (int i=0; i<MAX_ALUNOS; i++) {
        alunos[i].media = calcula_media(&alunos[i]);
    }
    return;
}

void exibe_relatorio(Aluno *alunos) {
    for (int i=0; i<MAX_ALUNOS; i++) {
        printf("NOME %s, MEDIA %.2f\n", alunos[i].nome, alunos[i].media);
    }
    return;
}

int main() {

    Aluno alunos[MAX_ALUNOS];

    cria_alunos(alunos);
    fechamento_media_alunos(alunos);
    exibe_relatorio(alunos);

    return 0;
}