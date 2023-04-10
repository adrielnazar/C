#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[5][50], curso[5][50];
    int matricula[5];
}aluno;

int main(int argc, char const *argv[])
{
    int i, m, retorno = -1;
    setlocale(LC_ALL, "Portuguese");
    aluno Estudante;

    for (i = 1; i < 6; i++)
    {
        printf("Escreva o nome do %dº aluno: ", i);
        fflush(stdin);
        fgets(Estudante.nome[i], 50, stdin);
        printf("Escreva o curso do %dº aluno: ", i);
        fflush(stdin);
        fgets(Estudante.curso[i], 50, stdin);
        do
        {
            printf("Escreva a matricula do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%d", &Estudante.matricula[i]);
            for(m=1; m < i; m++)
            {
            	if(Estudante.matricula[m] == Estudante.matricula[i])
            	{
            		retorno = 0;
				}
			}
            if (retorno == 0 || Estudante.matricula[i] <=0 || Estudante.matricula[i] >= 100000000)
                {
                    system("cls");
                    printf("Escreva em um formato valido!\n");
                    retorno = 0;
                }
            
        } while (retorno == 0);
        system("cls");
        
    }

    
    printf("\n\nAlunos matriculados no banco de dados\n\n");
    for (i = 1; i < 6; i++)
    {
        printf("Aluno: %sCurso: %sMatricula: %d\n\n", Estudante.nome[i], Estudante.curso[i], Estudante.matricula[i]);
    }
    
    return 0;
}

