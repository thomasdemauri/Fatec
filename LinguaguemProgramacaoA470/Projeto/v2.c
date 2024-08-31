#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 4
#define BASIC_BUFFET 50
#define MEDIUM_BUFFET 80
#define DELUXE_BUFFET 120
#define DISCOUNT_1 0.10
#define DISCOUNT_2 0.15
#define EXCLUSIVE_SERVICE_TAX 0.10
#define BF_BASICO 1
#define BF_PREMIUM 2
#define BF_DELUXE 3

void definePriceByCategory();
bool limitExceeded();
void addContract();
void showAllContracts();
int showMenu();
void showHeader();
void showResults();
void showContractByIndex(int index);
void orderByTotalValue();
bool wantsToContinue();
void initializeArrays();
void limitMessage();
void calculateBaseValue();
void calculateAdditionalTaxes();
void calculateDiscountByQtyPeople();
void calculateTotalValue();
void calculate();
float calculateAvgAll();
int calculateGreaterValue();
float calculateBuffetTypePercentage(int buffetType);
int calculateTotalPeople();
float calculateAvgExclusiveService();

typedef struct _subscription
{
    int idSubscription;
    int buffetCategoryType;
    int qtyPeople;
    int exclusiveService;  
    float pricePerPerson;
    float buffetTypeeValue;
    float additionalTaxes;
    float discountByQtyPeople;
    float baseValue;
    float totalValue;
} Subscription;

Subscription subscriptions[LEN];

int currentIndex = 0;

int main() {
    int exitMenu = false;

    initializeArrays();

    while (!exitMenu) {
        int option = showMenu();

        switch (option) {
            case 0:
                exitMenu = true;
                break;

            case 1:
                addContract();
                break;

            case 2:
                showResults();
                break;

            case 3:
                orderByTotalValue();
                break;

            case 4:
                showAllContracts();
                break;

            default:
                printf("OPCAO INVALIDA! USE [0-4] PARA NAVEGAR ENTRE AS OPCOES!\n");
                break;
        }
    }
    
    return 0;
}

void showResults() {
    system("cls");
    printf("########### TELA DE RESULTADOS ##############\n\n");
    printf("MEDIA DO TOTAL DE INSCRICOES: %.2f\n", calculateAvgAll());
    printf("MEDIA DAS INSCRICOES QUE INCLUEM BEBIDAS EXCLUSIVAS: %.2f\n", calculateAvgExclusiveService());
    printf("NUMERO DE INSCRICAO COM MAIOR VALOR: %d\n", calculateGreaterValue());
    printf("PERCENTUAL DAS INSCRICOES PARA O BUFFET DELUXE EM RELACAO AO NUMERO TOTAL DE INSCRICOES: %.2f%%\n", calculateBuffetTypePercentage(BF_DELUXE));
    printf("TOTAL GERAL DE PESSOAS INSCRITAS: %d\n", calculateTotalPeople());
    puts("");
    system("pause");
}

int calculateTotalPeople() {
    int acc=0;
    for (int i=0; i<LEN; i++) {
        acc += subscriptions[i].qtyPeople; 
    }
    return acc;
}

/* 
    Calcula a porcentagem da relacao entre os buffets totais e o buffet escolhido. 
    Para isso e necessario conferir quantas inscricoes estao de fato efetivadas em vez
    de levar em consideracao o tamanho total do array.
*/
float calculateBuffetTypePercentage(int buffetType) {
    int typeSubscriptions = 0, allSubscriptions = 0;
    for (int i=0; i<LEN; i++) {

        if (subscriptions[i].idSubscription == (int) NULL) {
            continue;
        }

        allSubscriptions++;

        if (subscriptions[i].buffetCategoryType == buffetType) { typeSubscriptions++; }
    }

    return ((float)typeSubscriptions / (float)allSubscriptions) * 100;
}

float calculateAvgAll() {
    float acc = 0, allSubscriptions = 0;

    for (int i=0; i<LEN; i++) {

        if (subscriptions[i].idSubscription == 0) {
            continue;
        }

        allSubscriptions++;

        acc += subscriptions[i].totalValue;
    }

    return  acc / allSubscriptions;
}

float calculateAvgExclusiveService() {
    float acc = 0, avg = 0;
    int counter = 0;

    for (int i=0; i<LEN; i++) {
        if (subscriptions[i].exclusiveService == 1) {
            acc += subscriptions[i].totalValue;
            counter++;
        }
    }

    return avg = acc / counter;
}

/* 
    Retorna o ID de maior inscricao.
    Pergunta se o vizinho (posicao atual + 1) e maior que a propria posicao e 
    o maior valor sera armazenado na variavel responsavel.
*/
int calculateGreaterValue() {
    int gtIdSubscription = -1;

    for (int i=0; i<LEN; i++) {

        if (i > LEN - 2) {
            break;
        }

        if (subscriptions[i + 1].totalValue > subscriptions[i].totalValue) {
            gtIdSubscription = subscriptions[i + 1].idSubscription;
        }
    }

    return gtIdSubscription; 
}

/*
    Passa em cada posicao perguntando se o vizinho e maior, em caso positivo
    troca de posicao e para isso e necessario criar as variaveis temporarias.
    Neste caso, e necessario perguntar para cada item o total de vezes que o tamanho do array.

    Lembrete: Posso otimizar o codigo substituindo o LEN pelo valor exato de inscricoes efetivadas.
*/
void orderByTotalValue() {

    int tmpIdSubscription;
    int tmpBuffetCategoryType;
    int tmpQtyPeople;
    int tmpExclusiveService;  
    float tmpPricePerPerson;
    float tmpBaseValue;
    float tmpAdditionalTaxes;
    float tmpDiscountByQtyPeople;
    float tmpTotalValue;

    for (int i=0 ; i<LEN; i++) {
        for (int j=0; j<LEN; j++) {
            if (subscriptions[j + 1].totalValue > subscriptions[j].totalValue) {
                tmpIdSubscription = subscriptions[j].idSubscription;
                tmpBuffetCategoryType = subscriptions[j].buffetCategoryType;
                tmpQtyPeople = subscriptions[j].qtyPeople;
                tmpExclusiveService = subscriptions[j].exclusiveService;
                tmpPricePerPerson = subscriptions[j].pricePerPerson;
                tmpBaseValue = subscriptions[j].baseValue;
                tmpAdditionalTaxes = subscriptions[j].additionalTaxes;
                tmpDiscountByQtyPeople = subscriptions[j].discountByQtyPeople;
                tmpTotalValue = subscriptions[j].totalValue;

                subscriptions[j].idSubscription = subscriptions[j + 1].idSubscription;
                subscriptions[j].buffetCategoryType = subscriptions[j + 1].buffetCategoryType;
                subscriptions[j].qtyPeople = subscriptions[j + 1].qtyPeople;
                subscriptions[j].exclusiveService = subscriptions[j + 1].exclusiveService;
                subscriptions[j].pricePerPerson = subscriptions[j + 1].pricePerPerson;
                subscriptions[j].baseValue = subscriptions[j + 1].baseValue;
                subscriptions[j].additionalTaxes = subscriptions[j + 1].additionalTaxes;
                subscriptions[j].discountByQtyPeople = subscriptions[j + 1].discountByQtyPeople;
                subscriptions[j].totalValue = subscriptions[j + 1].totalValue;

                subscriptions[j + 1].idSubscription = tmpIdSubscription;
                subscriptions[j + 1].buffetCategoryType = tmpBuffetCategoryType;
                subscriptions[j + 1].qtyPeople = tmpQtyPeople;
                subscriptions[j + 1].exclusiveService = tmpExclusiveService;
                subscriptions[j + 1].pricePerPerson = tmpPricePerPerson;
                subscriptions[j + 1].baseValue = tmpBaseValue;
                subscriptions[j + 1].additionalTaxes = tmpAdditionalTaxes;
                subscriptions[j + 1].discountByQtyPeople = tmpDiscountByQtyPeople;
                subscriptions[j + 1].totalValue = tmpTotalValue;
            }
        }
    }
}

/*
    Calcula o valor base da inscricao, sem descontos ou acrescimos.
*/
void calculateBaseValue() {
    subscriptions[currentIndex].baseValue = subscriptions[currentIndex].qtyPeople * subscriptions[currentIndex].pricePerPerson;
    return;
}

/*
    Define o preco por categoria
*/
void definePriceByCategory() {
    switch (subscriptions[currentIndex].buffetCategoryType) {
    case BF_BASICO:
        subscriptions[currentIndex].pricePerPerson = BASIC_BUFFET;
        break;
    case BF_PREMIUM:
        subscriptions[currentIndex].pricePerPerson = MEDIUM_BUFFET;
        break;
    case BF_DELUXE:
        subscriptions[currentIndex].pricePerPerson = DELUXE_BUFFET;
        break;
    default:
        subscriptions[currentIndex].pricePerPerson = 0;
        break;
    }
    return;
}

/*
    Verifica atraves do indice se o array esta cheio. Caso o indice seja igual o tamanho
    do array ja esta no limite. Pois, o ultimo indice disponivel e len - 1
*/
bool limitExceeded() {
    return currentIndex >= LEN ? true : false;
}

/*
    Calcula a taxa adicional de servico exclusivo de bebida
*/
void calculateAdditionalTaxes() {
    if (subscriptions[currentIndex].exclusiveService == 1) {
        subscriptions[currentIndex].additionalTaxes = EXCLUSIVE_SERVICE_TAX * subscriptions[currentIndex].baseValue;
    }
    return;
}

/*
    Calcula os descontos a partir do numero de pessoas no evento
*/
void calculateDiscountByQtyPeople() {
    if (subscriptions[currentIndex].qtyPeople > 20 && subscriptions[currentIndex].qtyPeople <= 50) {
        subscriptions[currentIndex].discountByQtyPeople = DISCOUNT_1 * subscriptions[currentIndex].baseValue;
    }
    
    if (subscriptions[currentIndex].qtyPeople > 50) {
        subscriptions[currentIndex].discountByQtyPeople = DISCOUNT_2 * subscriptions[currentIndex].baseValue;
    }
    return;
}

/*
    Calcula o valor final com taxas e acrescimos
*/
void calculateTotalValue() {
    subscriptions[currentIndex].totalValue = subscriptions[currentIndex].baseValue 
                                + subscriptions[currentIndex].additionalTaxes 
                                - subscriptions[currentIndex].discountByQtyPeople;
    return;
}

/*
    Responsavel por organizar a ordem de todos os calculos da inscricao
*/
void calculate() {
    definePriceByCategory();
    calculateBaseValue();
    calculateAdditionalTaxes();
    calculateDiscountByQtyPeople();
    calculateTotalValue();
}

void limitMessage() {
    system("cls");
    printf("\nNUMEROS DE CONTRATOS NO LIMITE!\n\n");
    system("pause");
    return;
}

void addContract() {
    if (limitExceeded()) {
        limitMessage();
    } else {
        // Permite adicionar mais contratos somente se nao estiver no limite.
        for (;currentIndex<LEN;) {
            system("cls");

            subscriptions[currentIndex].idSubscription = currentIndex + 1;
            printf("........COD CONTRATO => %d\n", subscriptions[currentIndex].idSubscription);

            printf("......TIPO BUFFET [1] Basico [2] | PREMIUM | [3] DELUXE => ");
            scanf("%d", &subscriptions[currentIndex].buffetCategoryType);

            printf(".........QTD PESSOAS => ");
            scanf("%d", &subscriptions[currentIndex].qtyPeople);

            printf("SERVICO DE BEBIDAS EXCLUSIVO? => ");
            scanf("%d", &subscriptions[currentIndex].exclusiveService);

            calculate();

            currentIndex++;

            if (!wantsToContinue()) {
                break;
            }

            if (currentIndex == LEN) {
                limitMessage();
            }
        }
    }
}

/*
    Responsavel por confirmar se o usuario quer continuar adicionando
    inscricoes, caso negativo volta para o menu inicial, retornando falso
*/
bool wantsToContinue() {
    int keepAdding = -1;

    system("cls");
    printf("INCLUIDO COM SUCESSO!\n");
    printf("\nCONTINUAR ADICIONANDO? [1] SIM [ANY] NAO => ");
    scanf("%d", &keepAdding);

    return keepAdding != 1 ? false : true;
}

void showHeader() {
    system("cls");

    printf("%-17s %-14s %-18s %-15s %-21s %-11s %-10s %-11s %-12s\n", 
        "COD. INSCRICAO |","TIPO BUFFET |", "VALOR P/ PESSOA |", "QTD. PESSOAS |", 
        "SERVICO DE BEBIDAS |", "VALOR BASE","DESCONTOS", "ACRESCIMOS", "VALOR TOTAL"
    );
    
    for (int j=0; j<136; j++) {printf("-");}

    puts("");

    return;
}

void showAllContracts() {
    showHeader();
    
    for (int i=0; i<currentIndex; i++) { showContractByIndex(i); }

    system("pause");
}

void showContractByIndex(int index) {
    char buffetCategory[10];
    switch (subscriptions[index].buffetCategoryType)
    {
        case 1:
            strcpy(buffetCategory, "BASICO");
            break;
        case 2:
            strcpy(buffetCategory, "PREMIUM");
            break;
        case 3:
            strcpy(buffetCategory, "DELUXE");
            break;
        default:
            strcpy(buffetCategory, "NULL");
            break;
    }

    printf("%-17d %-14s %-18.2f %-15d %-21s %-11.2f %-10.2f %-11.2f %-12.2f\n", 
        subscriptions[index].idSubscription, buffetCategory, subscriptions[index].pricePerPerson, 
        subscriptions[index].qtyPeople, (subscriptions[index].exclusiveService==1?"Sim":"Nao"),
        subscriptions[index].baseValue, subscriptions[index].discountByQtyPeople, 
        subscriptions[index].additionalTaxes, subscriptions[index].totalValue
    );
}

int showMenu() {
    int option = -1; 
    do {
        system("cls");
        printf("\nMenu\n");
        printf("[0] Sair\n");
        printf("[1] Inserir contratos\n");
        printf("[2] Apresentar resultados\n");
        printf("[3] Ordernar os contratos pelo valor total (descrescente)\n");
        printf("[4] Imprimir registros de contratos\n");
        printf("Ir para => ");
        scanf("%d", &option);
    } while (option < 0 || option > 4);

    return option;
}

void initializeArrays() {

    for (int i=0; i<LEN; i++) {
        subscriptions[i].idSubscription = 0;
        subscriptions[i].buffetCategoryType = 0;
        subscriptions[i].qtyPeople = 0;
        subscriptions[i].exclusiveService = 0;
        subscriptions[i].pricePerPerson = 0;
        subscriptions[i].additionalTaxes = 0;
        subscriptions[i].discountByQtyPeople = 0;
        subscriptions[i].buffetTypeeValue = 0;
        subscriptions[i].totalValue = 0;
        subscriptions[i].baseValue = 0;
    }
    return;
}