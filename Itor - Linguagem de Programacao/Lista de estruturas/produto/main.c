#include <stdio.h>
#include <string.h>

typedef struct {
    char  nome[30];
    float preco;
    int   qtd;
} Produto;


int main() {

    float vlr_total = 0;
    Produto produtos[2];

    for (int i=0; i<2; i++) {
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        strtok(produtos[i].nome, "\n");
        scanf("%f", &produtos[i].preco);
        getchar();
        scanf("%d", &produtos[i].qtd);
        getchar();
    }


    for (int i=0; i<2; i++) {
        vlr_total += produtos[i].qtd * produtos[i].preco;
        printf("Produto %d: %s | R$ %.2f | %d UN\n", i+1, produtos[i].nome, produtos[i].preco, produtos[i].qtd);
    }
    printf("Valor total: %.2f\n", vlr_total);

    return 0;
}