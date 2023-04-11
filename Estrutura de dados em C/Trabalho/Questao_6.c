#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int dia, mes, ano;
}Date;


typedef struct {
    Date dataNac;
    long long int CPF;
    int idade, codigoSet;
    char nome[50], sexo, cargoOcup[30];
    float salario;
}empregado;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    empregado funcionario;
    int retorno = 0;

    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    


    printf("Digite o nome do Funcionário: ");
    fflush(stdin);
    fgets(funcionario.nome, 50, stdin);
    /*do
    {
        printf("Digite a idade do funcionário: ");
        fflush(stdin);
        retorno = scanf("%d", funcionario.idade);
        if (retorno == 0 || funcionario.idade > 140 || funcionario.idade < 18);
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);*/
    
    do
    {
        printf("Digite o sexo do funcionário no formato M/F: ");
        fflush(stdin);
        scanf("%c", &funcionario.sexo);
        funcionario.sexo = toupper(funcionario.sexo);

        retorno = 1;
        

        if (funcionario.sexo != 'M' && funcionario.sexo != 'F' && funcionario.sexo != 'm' && funcionario.sexo != 'f')
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);

    do
    {
        printf("Digite o CPF do funcionário: ");
        fflush(stdin);
        retorno = scanf("%lld", &funcionario.CPF);
        
        if (retorno == 0 || funcionario.CPF > 99999999999 || funcionario.CPF < 9999999999)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);


    do
    {
        printf("Digite a data de nacimento do Funcionário no formato dd mm aaaa: ");
        fflush(stdin);
        retorno = scanf("%d%d%d", &funcionario.dataNac.dia, &funcionario.dataNac.mes, &funcionario.dataNac.ano);
        
        if (retorno == 0 || funcionario.dataNac.dia > 31 || funcionario.dataNac.dia < 1 || funcionario.dataNac.mes > 12 ||
        funcionario.dataNac.mes < 1 || funcionario.dataNac.ano > 2006 || funcionario.dataNac.ano < 1898)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
        
    } while (retorno == 0);
    
    funcionario.idade = (data_hora_atual->tm_year+1899) - funcionario.dataNac.ano;
    if (data_hora_atual->tm_mon+1 >= funcionario.dataNac.mes)
    {
        if (data_hora_atual->tm_mon+1 == funcionario.dataNac.mes)
	    {
	        if (data_hora_atual->tm_mday >= funcionario.dataNac.dia)
	        {
	            funcionario.idade++;
	        }   
	    } else if (data_hora_atual->tm_mon+1 > funcionario.dataNac.mes){
	    	funcionario.idade++;
		}
    }

    do
    {
        printf("Digite o Código do sertor do funcionário (Entre: 0-99): ");
        fflush(stdin);
        retorno = scanf("%d", &funcionario.codigoSet);
        
        if (retorno == 0 || funcionario.codigoSet > 99 || funcionario.codigoSet < 0)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);

    printf("Digite o cargo ocupado pelo Funcionário: ");
    fflush(stdin);
    fgets(funcionario.cargoOcup, 30, stdin);

    do
    {
        printf("Digite o Salário do funcionário: ");
        fflush(stdin);
        retorno = scanf("%f", &funcionario.salario);
        
        if (retorno == 0 || funcionario.salario > 99999999 || funcionario.salario < 0)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);



        
    printf("\n\n        --Dados do funcionario no banco de dados--\n\n");

    printf("Nome: %sIdade: %d\nSexo: %c\nCPF: %lld\nData de nacimento: %d/%d/%d\nCódigo do setor: %d\nCargo Ocupado: %sSalário: %.2f",
    funcionario.nome, funcionario.idade , funcionario.sexo, funcionario.CPF, funcionario.dataNac.dia, 
    funcionario.dataNac.mes, funcionario.dataNac.ano, funcionario.codigoSet, funcionario.cargoOcup, funcionario.salario);

    return 0;
}
