#include <stdio.h>
#include <string.h>

typedef struct {
    char  nome[30];
    float preco;
    int   qtd;
} Produto;


int main() {
    int max_prod = 5;
    float vlr_total = 0;
    Produto produtos[max_prod];

    for (int i=0; i<max_prod; i++) {
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        strtok(produtos[i].nome, "\n");
        scanf("%f", &produtos[i].preco);
        getchar();
        scanf("%d", &produtos[i].qtd);
        getchar();
    }


    for (int i=0; i<max_prod; i++) {
        vlr_total += produtos[i].qtd * produtos[i].preco;
        printf("Produto %d: %s | R$ %.2f | %d UN\n", i+1, produtos[i].nome, produtos[i].preco, produtos[i].qtd);
    }
    printf("Valor total: %.2f\n", vlr_total);

    return 0;
}