#include <stdio.h>
#include <locale.h>

typedef struct {
    int matricula[10], codigo[10];
    char nome[10][50];
    float nota1[10], nota2[10], media[10];
}estudantes;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    estudantes aluno;
    int i, retorno = 0;


    for ( i = 1; i < 11; i++) {
        
        printf("Digite o nome do %dº aluno: ", i);
        fflush(stdin);
        fgets(aluno.nome[i], 50, stdin);
        do
        {
            printf("Digite a matricula do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%d", &aluno.matricula[i]);
            if (retorno == 0 || aluno.matricula[i] <= 0 || aluno.matricula[i] >= 100000000)
            {
                system("cls");
                printf("Escreva em um formato valido!\n");
                retorno = 0;
            }
            
        } while (retorno == 0);
        
        do
        {
            printf("Digite a código da diciplina do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%d", &aluno.codigo[i]);
            if (retorno == 0 || aluno.codigo[i] <= 0 || aluno.codigo[i] >= 100000000)
            {
                system("cls");
                printf("Escreva em um formato valido!\n");
                retorno = 0;
            }
            
        } while (retorno == 0);
        
        do
        {
            printf("Digite a primeira nota do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%f", &aluno.nota1[i]);
            if (retorno == 0 || aluno.nota1[i] < 0 || aluno.nota1[i] > 10)
            {
                system("cls");
                printf("Escreva em um formato valido!\n");
                retorno = 0;
            }
            
        } while (retorno == 0);
            
        do
        {
            printf("Digite a segunda nota do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%f", &aluno.nota2[i]);
            if (retorno == 0 || aluno.nota2[i] < 0 || aluno.nota2[i] > 10)
            {
                system("cls");
                printf("Escreva em um formato valido!\n");
                retorno = 0;
            }
            
        } while (retorno == 0);
    system("cls");
    
    aluno.media[i] = (aluno.nota1[i] + (aluno.nota2[i] * 2))/3;

	}

        
    printf("\n\n        --Alunos cadastrados no banco de dados--\n\n");

    for ( i = 1; i < 11; i++){
        printf("Aluno: %sMatrícula: %d\nCódigo da Diciplina: %d\nPrimeira nota: %.1f\nSegunda nota: %.1f\nMédia: %.1f\n", 
        aluno.nome[i], aluno.matricula[i],aluno.codigo[i], aluno.nota1[i], aluno.nota2[i], aluno.media[i]);
        if (aluno.media[i] >= 6)
        {
            printf("Aluno Aprovado!\n\n");
        } else
        {
            printf("Aluno Reprovado!\n\n");
        }
    }
return 0;
}
