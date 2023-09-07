 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
//estrutura das contas
typedef struct {
    char nome[100];
    int numero;
    float saldo;
} conta;

void cadastro(conta *contaPtr, int quantidadeContas, conta Contas[]) {//func para cadastrar contas

    int loop = 1;
    int numeroConta = 0, voltar = 0;
    while (loop != 0){

        printf("Digite o numero da conta: ");
        scanf("%d", &numeroConta);
        voltar = 0;
        
        for (int i = 0; i < quantidadeContas; ++i) {
            if (numeroConta == Contas[i].numero){//bloquear duas contas com numeros iguais
                printf("\n|-----------------------------------|\n");
                printf("| Numero invalido, conta ja existente |\n");
                printf("|-------------------------------------|\n");
                system("pause");
                system("cls");
                voltar = 1;
            }
        }
        
        if(voltar == 1)
            loop = 1;
        else
            loop = 0;
    }

    (*contaPtr).numero = numeroConta;

    printf("Digite o nome da conta:");
    getchar();
    fgets(contaPtr -> nome, 99, stdin);
    printf("Digite o valor do seu saldo:");
    scanf ("%f", &contaPtr -> saldo);
    printf("\n");

}

void verificacao(conta Contas[], int quantidadeContas){//func para verificar se uma conta existe

    char nomeUsuario[50];
    int achado;

    printf("Digite o nome da conta:");
    getchar();
    fgets(nomeUsuario, 49, stdin);

    for (int i = 0; i < quantidadeContas; ++i) {
        if (strcmp(nomeUsuario, Contas[i].nome) == 0){//verificar se existe a conta com o nome ddigitado na linha 53
            printf("=========================\n");
            printf("======DADOS DA CONTA=====\n");
            printf("=========================\n");
            printf("\n");
            printf("|-----------------------|\n");
            printf("| Nome: %s",Contas[i].nome);
            printf("| Numero: %d\n",Contas[i].numero);
            printf("| Saldo: %.2f\n",Contas[i].saldo);
            printf("|-----------------------|\n");
            achado = 1;
            break;
        }
    }
    if (achado != 1){
        printf("===========================\n");
        printf("====CONTA NAO ENCONTRADA===\n");
        printf("===========================\n");
    }
}
void remocao(conta Contas[], int quantidadeContas){//func para a remocao de uma conta
    int menor = 0;
    if (quantidadeContas == 0){//caso nao exista nenhuma conta
        printf("|-----------------------------|\n");
        printf("| Nao existe conta cadastrada |\n");
        printf("|-----------------------------|\n");
        system("pause");
        system("cls");
    }

    for (int i = 0; i < quantidadeContas; ++i){//verificar o meno saldo
        if (Contas[i].saldo < Contas[menor].saldo)
            menor = i;
    }

    for (int i = menor; i < quantidadeContas; ++i)//realocar as contas no
        Contas[i] = Contas[i + 1];

    --quantidadeContas;

    printf("=========================\n");
    printf("======CONTA REMOVIDA=====\n");
    printf("=========================\n");
    system("pause");
    system("cls");

}
//main
int main() {

    int quantidadeContas = 0;
    conta Contas[15];
    conta *contaPtr = Contas;

    int selecioneOperacap;

    do {
        printf("=========================\n");
        printf("========= BANCO =========\n");
        printf("=========================\n");
        printf("\n");
        printf("|-----------------------|\n");
        printf("| 1.Cadastrar conta     |\n");
        printf("| 2.Verificar conta     |\n");
        printf("| 3.Exluir conta        |\n");
        printf("| 4.Sair                |\n");
        printf("|-----------------------|\n");
        printf("Selecione a operacao:");
        scanf("%d", &selecioneOperacap);
        printf("\n");

        switch (selecioneOperacap) {
            case 1:
                if(quantidadeContas < 15 + 1){
                    cadastro(contaPtr, quantidadeContas, Contas);
                    printf("=========================\n");
                    printf("=====CONTA CADASTRADA====\n");
                    printf("=========================\n");
                    system("pause");
                    system("cls");
                    ++quantidadeContas;
                    ++contaPtr;
                }else{
                    printf("=========================\n");
                    printf("=====LIMITE ALCANCADO====\n");
                    printf("=========================\n");
                }
                break;
            case 2:
                verificacao(Contas, quantidadeContas);
                system("pause");
                system("cls");
                break;
            case 3:
                remocao(Contas, quantidadeContas);
                break;
            case 4:
                selecioneOperacap = 4;
                break;
            default:
                printf("==========================\n");
                printf("=====OPERACAO INVALIDA====\n");
                printf("==========================\n");
                break;
        }


    }while(selecioneOperacap != 4);


    return 0;
}

