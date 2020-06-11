#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//VARIÁVEIS
char nome[40];
char cpf[15];
char rg[15];
char *endereco;
char cidade[30];
char uf[2];
char email[100];
char telefone[15];
char confirmacao[2];

int codigo_empregado;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("CADASTRO DE CONSUMIDOR\n");
    printf("----------------------\n");

//MARCA O TRECHO DO CÓDIGO, CASO TENHA QUE SER REPETIDO
cadastro:

    printf("Digite o nome do consumidor: ");
    scanf("%s", &nome);

    printf("\nDigite o CPF do consumidor: ");
    scanf("%s", &cpf);

    printf("\nDigite o RG do consumidor: ");
    scanf("%s", &rg);

    printf("\nDigite o endereco do consumidor: ");
    scanf("%s", &endereco);

    printf("\nDigite a cidade do consumidor: ");
    scanf("%s", &cidade);

    printf("\nDigite a UF do estado do consumidor: ");
    scanf("%s", &uf);

    printf("\nDigite o email do consumidor: ");
    scanf("%s", &email);

    printf("\nDigite o telefone do consumidor: ");
    scanf("%s", &telefone);

funcionario:

    printf("\nFuncionários (código - nome): ");
    printf("\n101 - Maria Joana");
    printf("\n102 - Paulo Henrique");
    printf("\n103 - Jõao Miguel");

    printf("\nDigite o códido do funcionário responsavel por cadastrar esse consumidor: ");
    scanf("%i", &codigo_empregado);

    printf("CONFIRMAÇÃO DE INFORMAÇÃO\n");
    printf("----------------------\n");

    printf("Nome: %s", &nome);
    printf("CPF: %s", &cpf);
    printf("RG: %s", &rg);
    printf("Endereco: %s", &endereco);
    printf("Cidade: %s", &cidade);
    printf("UF: %s", &uf);
    printf("Email: %s", &email);
    printf("Telefone: %s", &telefone);

    //VERIFICA QUAL FUNCIONÁRIO FOI SELECONADO
    switch (codigo_empregado)
    {
    case 101:
        printf("\nFuncionário: 101 - Maria Joana");
        break;
    case 102:
        printf("\nFuncionário: 102 - Paulo Henrique");
        break;
    case 103:
        printf("\nFuncionário: 103 - Jõao Miguel");
        break;

    default:
        printf("\nFuncionário não encotrado, tente novamente");
        goto funcionario;
        break;
    }

    //VERIFICA SE FUNCIONÁRIO QUE ESTÁ ADTRANDO O CONSUMIDOR DESEJA ALTERAR
    //ALGUMA INFORMAÇÃO
    printf("\nApós conferir os dados que serão cadastrados, deseja corrigir alguma informação? (s/n)");
    scanf("%s", &confirmacao);

    if (strcmp("s", confirmacao) == 0 || strcmp("S", confirmacao) == 0)
    {
        goto cadastro;
    }
    else
    {
        printf("Consumidor cadastrado com sucesso.");
    }

    getch();

    return 0;
}