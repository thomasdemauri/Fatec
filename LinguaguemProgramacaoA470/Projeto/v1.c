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

int idSubscription[LEN];
int buffetCategoryType[LEN];
int qtyPeople[LEN];
int exclusiveService[LEN];  
float pricePerPerson[LEN];
float buffetTypeeValue[LEN];
float additionalTaxes[LEN];
float discountByQtyPeople[LEN];
float baseValue[LEN];
float totalValue[LEN];

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
        acc += qtyPeople[i]; 
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

        if (idSubscription[i] == 0) {
            continue;
        }

        allSubscriptions++;

        if (buffetCategoryType[i] == buffetType) { typeSubscriptions++; }
    }

    return ((float)typeSubscriptions / (float)allSubscriptions) * 100;
}

float calculateAvgAll() {
    float acc = 0, allSubscriptions = 0;

    for (int i=0; i<LEN; i++) {

        if (idSubscription[i] == 0) {
            continue;
        }

        allSubscriptions++;

        acc += totalValue[i];
    }

    return acc / allSubscriptions;
}

float calculateAvgExclusiveService() {
    float acc = 0, avg = 0;
    int counter = 0;

    for (int i=0; i<LEN; i++) {
        if (exclusiveService[i] == 1) {
            acc += totalValue[i];
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
    int gtIdSubscription = 0;

    for (int i=0; i<LEN; i++) {

        if (i > LEN - 2) {
            break;
        }

        if (totalValue[i + 1] > totalValue[i]) {
            gtIdSubscription = idSubscription[i + 1];
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
            if (totalValue[j + 1] > totalValue[j]) {
                tmpIdSubscription = idSubscription[j];
                tmpBuffetCategoryType = buffetCategoryType[j];
                tmpQtyPeople = qtyPeople[j];
                tmpExclusiveService = exclusiveService[j];
                tmpPricePerPerson = pricePerPerson[j];
                tmpBaseValue = baseValue[j];
                tmpAdditionalTaxes = additionalTaxes[j];
                tmpDiscountByQtyPeople = discountByQtyPeople[j];
                tmpTotalValue = totalValue[j];

                idSubscription[j] = idSubscription[j + 1];
                buffetCategoryType[j] = buffetCategoryType[j + 1];
                qtyPeople[j] = qtyPeople[j + 1];
                exclusiveService[j] = exclusiveService[j + 1];
                pricePerPerson[j] = pricePerPerson[j + 1];
                baseValue[j] = baseValue[j + 1];
                additionalTaxes[j] = additionalTaxes[j + 1];
                discountByQtyPeople[j] = discountByQtyPeople[j + 1];
                totalValue[j] = totalValue[j + 1];

                idSubscription[j + 1] = tmpIdSubscription;
                buffetCategoryType[j + 1] = tmpBuffetCategoryType;
                qtyPeople[j + 1] = tmpQtyPeople;
                exclusiveService[j + 1] = tmpExclusiveService;
                pricePerPerson[j + 1] = tmpPricePerPerson;
                baseValue[j + 1] = tmpBaseValue;
                additionalTaxes[j + 1] = tmpAdditionalTaxes;
                discountByQtyPeople[j + 1] = tmpDiscountByQtyPeople;
                totalValue[j + 1] = tmpTotalValue;
            }
        }
    }
}

/*
    Calcula o valor base da inscricao, sem descontos ou acrescimos.
*/
void calculateBaseValue() {
    baseValue[currentIndex] = qtyPeople[currentIndex] * pricePerPerson[currentIndex];
    return;
}

/*
    Define o preco por categoria
*/
void definePriceByCategory() {
    switch (buffetCategoryType[currentIndex]) {
    case BF_BASICO:
        pricePerPerson[currentIndex] = BASIC_BUFFET;
        break;
    case BF_PREMIUM:
        pricePerPerson[currentIndex] = MEDIUM_BUFFET;
        break;
    case BF_DELUXE:
        pricePerPerson[currentIndex] = DELUXE_BUFFET;
        break;
    default:
        pricePerPerson[currentIndex] = 0;
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
    if (exclusiveService[currentIndex] == 1) {
        additionalTaxes[currentIndex] = EXCLUSIVE_SERVICE_TAX * baseValue[currentIndex];
    }
    return;
}

/*
    Calcula os descontos a partir do numero de pessoas no evento
*/
void calculateDiscountByQtyPeople() {
    if (qtyPeople[currentIndex] > 20 && qtyPeople[currentIndex] <= 50) {
        discountByQtyPeople[currentIndex] = DISCOUNT_1 * baseValue[currentIndex];
    }
    
    if (qtyPeople[currentIndex] > 50) {
        discountByQtyPeople[currentIndex] = DISCOUNT_2 * baseValue[currentIndex];
    }
    return;
}

/*
    Calcula o valor final com taxas e acrescimos
*/
void calculateTotalValue() {
    totalValue[currentIndex] = baseValue[currentIndex] + additionalTaxes[currentIndex] - discountByQtyPeople[currentIndex];
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

            idSubscription[currentIndex] = currentIndex + 1;
            printf("........COD CONTRATO => %d\n", idSubscription[currentIndex]);

            printf("......TIPO BUFFET [1] Basico [2] | PREMIUM | [3] DELUXE => ");
            scanf("%d", &buffetCategoryType[currentIndex]);

            printf(".........QTD PESSOAS => ");
            scanf("%d", &qtyPeople[currentIndex]);

            printf("SERVICO DE BEBIDAS EXCLUSIVO? => ");
            scanf("%d", &exclusiveService[currentIndex]);

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
    switch (buffetCategoryType[index])
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
        idSubscription[index], buffetCategory, pricePerPerson[index], qtyPeople[index], (exclusiveService[index]==1?"Sim":"Nao"),
        baseValue[index], discountByQtyPeople[index], additionalTaxes[index], totalValue[index]
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
        idSubscription[i] = 0;
        buffetCategoryType[i] = 0;
        qtyPeople[i] = 0;
        exclusiveService[i] = 0;  
        pricePerPerson[i] = 0;
        additionalTaxes[i] = 0;
        discountByQtyPeople[i] = 0;
        buffetTypeeValue[i] = 0;
        totalValue[i] = 0;
        baseValue[i] = 0;
    }
    return;
}