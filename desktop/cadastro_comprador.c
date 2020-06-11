#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

//VARIÁVEIS
char nome[80];
char cpf[20];
char rg[20];
char endereco[100];
char cidade[80];
char uf[3];
char email[100];
char telefone[20];
char confirmacao[3];

int codigo_empregado;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("CADASTRO DE CONSUMIDOR\n");
    printf("----------------------\n");

//MARCA O TRECHO DO CÓDIGO, CASO TENHA QUE SER
cadastro:

    printf("Digite o nome do consumidor: ");
    scanf("%[^\n]%*c", &nome);

    printf("\nDigite o CPF do consumidor: ");
    scanf("%[^\n]%*c", &cpf);

    printf("\nDigite o RG do consumidor: ");
    scanf("%[^\n]%*c", &rg);

    printf("\nDigite o endereco do consumidor: ");
    scanf("%[^\n]%*c", &endereco);

    printf("\nDigite a cidade do consumidor: ");
    scanf("%[^\n]%*c", &cidade);

    printf("\nDigite a UF do estado do consumidor: ");
    scanf("%[^\n]%*c", &uf);

    printf("\nDigite o email do consumidor: ");
    scanf("%[^\n]%*c", &email);

    printf("\nDigite o telefone do consumidor: ");
    scanf("%[^\n]%*c", &telefone);

funcionario:

    printf("\nFuncionários (código - nome): ");
    printf("\n101 - Maria Joana");
    printf("\n102 - Paulo Henrique");
    printf("\n103 - Jõao Miguel");

    printf("\nDigite o códido do funcionário responsavel por cadastrar esse consumidor: ");
    scanf("%i", &codigo_empregado);

    printf("CONFIRMAÇÃO DE INFORMAÇÃO\n");
    printf("----------------------\n");

    printf("\nNome: %s", &nome);
    printf("\nCPF: %s", &cpf);
    printf("\nRG: %s", &rg);
    printf("\nEndereco: %s", &endereco);
    printf("\nCidade: %s", &cidade);
    printf("\nUF: %s", &uf);
    printf("\nEmail: %s", &email);
    printf("\nTelefone: %s", &telefone);

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
    scanf("%[^\n]%*c", &confirmacao);

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
