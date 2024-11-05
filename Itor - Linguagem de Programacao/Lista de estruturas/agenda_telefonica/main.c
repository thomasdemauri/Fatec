#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 64
#define MAX_AGENDA 100

typedef struct {
    char logradouro[MAX_CHARS];
    char numero[MAX_CHARS];
    char complemento[MAX_CHARS];
    char bairro[MAX_CHARS];
    char cep[MAX_CHARS];
    char cidade[MAX_CHARS];
    char estado[MAX_CHARS];
    char pais[MAX_CHARS];
} Endereco;

typedef struct {
    char ddd[MAX_CHARS];
    char numero[MAX_CHARS];
} Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char        nome[MAX_CHARS];
    char        email[MAX_CHARS];
    char        observacoes[MAX_CHARS];
    Endereco    endereco;
    Telefone    telefone;
    Data        nascimento;
} Contato;

// Cabecalho de funcoes
void adiciona_contato(Contato *contato);
void adiciona_endereco(Endereco *endereco);
void adiciona_telefone(Telefone *telefone);
void adiciona_data(Data *data);
void exibe_contato(Contato *contato);
void exibe_contatos(Contato *contato, int len);
void deleta_contato(Contato *contatos, int index);
void exibe_msg_sucesso();
int pesquisa_por(Contato *contatos, char *criterio_pesquisa, Contato *resultado, int filtro);
int menu_principal();

// Variaveis globais
int index_contatos = 0;

int main() {

    Contato contatos[MAX_AGENDA];
    Contato resultado[MAX_AGENDA];
    int len_resultado;
    int index_pesquisa;
    char criterio_pesquisa[30];

    bool sair = false;
    int  op;

    while (!sair) {
        op = menu_principal();

        switch (op) {
        case 1: 
            adiciona_contato(&contatos[index_contatos++]);
            exibe_msg_sucesso();
            
            printf("Pressione qualquer tecla para voltar...\n");
            getchar();
            break;
        case 2:
            printf("NOME: ");
            fgets(criterio_pesquisa, sizeof(criterio_pesquisa), stdin);

            len_resultado = pesquisa_por(contatos, criterio_pesquisa, resultado, 1);
            exibe_contatos(resultado, len_resultado);

            printf("Pressione qualquer tecla para voltar...\n");
            getchar();
            break;
        case 3:     
            printf("MES DESEJADO PARA PESQUISA: ");
            fgets(criterio_pesquisa, sizeof(criterio_pesquisa), stdin);

            len_resultado = pesquisa_por(contatos, criterio_pesquisa, resultado, 2);
            exibe_contatos(resultado, len_resultado);

            printf("Pressione qualquer tecla para voltar...\n");
            getchar();
            break;
        case 4:
            // Remove pessoa
            /**
             * O certo seria pesquisar pelo nome e retornar o index e entao deletar
             */
            printf("INDICE: \n");
            scanf("%d", &index_pesquisa);
            deleta_contato(contatos, index_pesquisa);
            break;
        case 5:
            exibe_contatos(contatos, index_contatos);

            printf("Pressione qualquer tecla para voltar...\n");
            getchar();
            break;
        case 6:
            sair = true;
            break;
        default:
            break;
        }
    }

    return 0;
}

void exibe_msg_sucesso() {
    system("clear");
    printf("Inserido com sucesso.\n");
    return;
}

void deleta_contato(Contato *contatos, int index) {
    Contato novo_contatos[MAX_AGENDA];
    for (int i=0, j=0; i<index_contatos; i++, j++) {
        if (i != index) {
            novo_contatos[j] = contatos[i];
        } else {
            j--;
            index_contatos--;
        }

    }
    for (int i=0; i<index_contatos; i++) {
        contatos[i] = novo_contatos[i];
    }

    return;
}

// Busca por nome
int pesquisa_por(Contato *contatos, char *criterio_pesquisa, Contato *resultado, int filtro) {

    int count = 0;

    strtok(criterio_pesquisa, "\n");
    
    switch (filtro) {
    case 1:

        // Pesquisa por nome
        for (int i=0; i<index_contatos; i++) {
            if (strstr(contatos[i].nome, criterio_pesquisa) != NULL) {
                resultado[count++] = contatos[i];
            }
        }

        return count;
        break;
    case 2:

        // Mes de aniversario
        int mes = atoi(criterio_pesquisa);
        for (int i=0; i<index_contatos; i++) {
            if (contatos[i].nascimento.mes == mes) {
                resultado[count++] = contatos[i];
            }
        }

        return count;
        break;
    default:
        break;
    }

    return -1;
}

// Insercao de pessoa
void adiciona_contato(Contato *contato) {

    printf("NOME: ");
    fgets(contato->nome, sizeof(contato->nome), stdin);
    strtok(contato->nome, "\n");

    printf("EMAIL: ");
    fgets(contato->email, sizeof(contato->email), stdin);
    strtok(contato->email, "\n");

    printf("OBSERVACOES: ");
    fgets(contato->observacoes, sizeof(contato->observacoes), stdin);
    strtok(contato->observacoes, "\n");

    adiciona_telefone(&contato->telefone);
    adiciona_data(&contato->nascimento);
    adiciona_endereco(&contato->endereco);

    return;
}

// Insercao de endereco
void adiciona_endereco(Endereco *endereco) {

    printf("LOGRADOURO: ");
    fgets(endereco->logradouro, sizeof(endereco->logradouro), stdin);
    strtok(endereco->logradouro, "\n");

    printf("NUMERO: ");
    fgets(endereco->numero, sizeof(endereco->numero), stdin);
    strtok(endereco->numero, "\n");

    printf("COMPLEMENTO: ");
    fgets(endereco->complemento, sizeof(endereco->complemento), stdin);
    strtok(endereco->complemento, "\n");

    printf("BAIRRO: ");
    fgets(endereco->bairro, sizeof(endereco->bairro), stdin);
    strtok(endereco->bairro, "\n");

    printf("CEP: ");
    fgets(endereco->cep, sizeof(endereco->cep), stdin);
    strtok(endereco->cep, "\n");

    printf("CIDADE: ");
    fgets(endereco->cidade, sizeof(endereco->cidade), stdin);
    strtok(endereco->cidade, "\n");

    printf("ESTADO: ");
    fgets(endereco->estado, sizeof(endereco->estado), stdin);
    strtok(endereco->estado, "\n");

    printf("PAIS: ");
    fgets(endereco->pais, sizeof(endereco->pais), stdin);
    strtok(endereco->pais, "\n");

    return;
}

// Insercao de telefone
void adiciona_telefone(Telefone *telefone) {

    printf("DDD: ");
    fgets(telefone->ddd, sizeof(telefone->ddd), stdin);
    strtok(telefone->ddd, "\n");

    printf("NUMERO: ");
    fgets(telefone->numero, sizeof(telefone->numero), stdin);
    strtok(telefone->numero, "\n");

    return;
} 

// Insercao de data
void adiciona_data(Data *data) {

    printf("DATA NASCIMENTO (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
    getchar();  

    return;
}

void exibe_contato(Contato *contato) {

    printf("==================================================\n");
    printf("NOME: %s\n", contato->nome);
    printf("TELEFONE: (%s) %s\n", contato->telefone.ddd, contato->telefone.numero);
    printf("ENDERECO: %s, %s - %s CEP: %s | %s, %s, %s\n",
        contato->endereco.logradouro, contato->endereco.numero,
        contato->endereco.bairro, contato->endereco.cep, contato->endereco.cidade,
        contato->endereco.estado, contato->endereco.pais
    );
    printf("NASCIMENTO: %02d/%02d/%04d\n", contato->nascimento.dia, contato->nascimento.mes, contato->nascimento.ano);
    printf("OBSERVACOES: %s\n", contato->observacoes);
    printf("==================================================\n");
    return;
}

void exibe_contatos(Contato *contatos, int len) {
    system("clear");
    for (int i=0; i<len; i++) {
        exibe_contato(&contatos[i]);
    }

    return;
}

// Remocao de pessoa

// Menu principal
int menu_principal() {
    system("clear");
    int op = -1;
    do {
        printf("[1] INSERIR CONTATO\n");
        printf("[2] BUSCAR POR NOME\n");
        printf("[3] BUSCAR POR MES DE ANIVERSARIO\n");
        printf("[4] REMOVER CONTATO\n");
        printf("[5] IMPRIMIR CONTATOS\n");
        printf("[6] SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &op);
        getchar();  // Limpa o buffer
    } while (op < 1 && op > 6);
    return op;
}