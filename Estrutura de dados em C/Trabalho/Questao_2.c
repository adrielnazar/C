#include <stdio.h>
#include <locale.h>

typedef struct{
    char nome[50], endereco[100];
    int idade;
}pessoa;

int main(int argc, char const *argv[])
{
    int retorno = -1;
    setlocale(LC_ALL, "Portuguese");
    pessoa Pessoa;
    
	printf("Escreva o nome da pessoa:");
	fflush(stdin);
    fgets(Pessoa.nome, 50, stdin);
    do{
        printf("Escreva a idade da pessoa:");
        fflush(stdin);
        retorno = scanf("%d", &Pessoa.idade);
        if (retorno == 0 || Pessoa.idade <=0)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
        
    } while (retorno == 0);
    
        
	printf("Escreva o endereço da pessoa:");
	fflush(stdin);
    fgets(Pessoa.endereco, 100, stdin);

    

    printf("\n\nNome: %sIdade: %d \nEndereço: %s", 
    Pessoa.nome, Pessoa.idade, Pessoa.endereco);
    return 0;
}
