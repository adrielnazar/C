#include <stdio.h>
#include <locale.h>

typedef struct {
    int matricula[5];
    char nome[5][50];
    float nota1[5], nota2[5], nota3[5], mediaM[5], mediam[5];
}estudantes;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    estudantes aluno;
    int i, x, m, retorno = 0, maiormed[5], menormed[6], maiorn1[5], contmn1 = 0, contmaiormed = 0 ;
    long long contmenormed = 0;
    maiorn1[1]=maiormed[1]=1;
    menormed[1]=1;
    aluno.nota1[maiorn1[1]]= -1;
    aluno.mediam[menormed[1]]=11;
    aluno.mediaM[maiormed[1]]=-1;


    for ( i = 1; i < 6; i++) {
        printf("Digite o nome do %dº aluno: ", i);
        fflush(stdin);
        fgets(aluno.nome[i], 50, stdin);
        do
        {
            printf("Digite a matricula do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%d", &aluno.matricula[i]);
            for(m=1; m < i; m++)
            {
            	if(aluno.matricula[m] == aluno.matricula[i])
            	{
            		retorno = 0;
				}
			}
            if (retorno == 0 || aluno.matricula[i] <= 0 || aluno.matricula[i] >= 100000000)
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
        
        do
        {
            printf("Digite a terceira nota do %dº aluno: ", i);
            fflush(stdin);
            retorno = scanf("%f", &aluno.nota3[i]);
            if (retorno == 0 || aluno.nota3[i] < 0 || aluno.nota3[i] > 10)
            {
                system("cls");
                printf("Escreva em um formato valido!\n");
                retorno = 0;
            }
        } while (retorno == 0);
        system("cls");


        aluno.mediaM[i] = aluno.mediam[i] = (aluno.nota1[i] + aluno.nota2[i] + aluno.nota3[i])/3; 

        if (aluno.nota1[i] >= aluno.nota1[maiorn1[1]]){
            if (aluno.nota1[i] == aluno.nota1[maiorn1[1]])
            {
                contmn1++;
            }else{
                contmn1=1;
                for (x = 1; x < 6; x++)
                {
                    maiorn1[x] = 0;
                }
            }
            maiorn1[contmn1] = i;
        };

        if (aluno.mediaM[i] >= aluno.mediaM[maiormed[1]]){
            if (aluno.mediaM[i] == aluno.mediaM[maiormed[1]])
            {
                contmaiormed++;
            }else{
                contmaiormed=1;
                for (x = 1; x < 6; x++)
                {
                    maiormed[x] = 0;
                }
            }
            maiormed[contmaiormed] = i;
        }

        if (aluno.mediam[i] <= aluno.mediam[menormed[1]]){
            
            if (aluno.mediam[i] == aluno.mediam[menormed[1]])
            {
                contmenormed++;
            }else{
                contmenormed=1;
                for (x = 1; x < 6; x++)
                {
                    menormed[x] = 0;
                }
            }
            menormed[contmenormed] = i;
        }    

        printf("%lld contmenormed \n",contmenormed);
    }

    printf("\n\n        --Alunos cadastrados no banco de dados--\n\n");

    for ( i = 1; i < 6; i++)
    {
        printf("Aluno: %sMatrícula: %d\nPrimeira nota: %.1f\nSegunda nota: %.1f\nTesceira nota: %.1f\nMédia: %.1f\n", 
        aluno.nome[i], aluno.matricula[i], aluno.nota1[i], aluno.nota2[i], aluno.nota3[i], aluno.mediaM[i]);
        if (aluno.mediaM[i] >= 6)
        {
            printf("Aluno Aprovado!\n\n");
        } else
        {
            printf("Aluno Reprovado!\n\n");
        }
    }

    printf("Alunos com maior primeira nota: \n");
    for (x = 1; x <= contmn1; x++)
    {
        printf("Aluno: %sMatrícula: %d\nPrimeira nota: %.1f\n\n", 
        aluno.nome[maiorn1[x]], aluno.matricula[maiorn1[x]], aluno.nota1[maiorn1[x]]);
    }

    printf("Alunos com maior média nas notas: \n");
    for (x = 1; x <= contmaiormed; x++)
    {
        printf("Aluno: %sMatrícula: %d\nMédia: %.1f\n\n", 
        aluno.nome[maiormed[x]], aluno.matricula[maiormed[x]], aluno.mediaM[maiormed[x]]);
    }

    printf("Alunos com menor média nas notas: \n");
    for (x = 1; x <= contmenormed; x++)
    {
        
        printf("Aluno: %sMatrícula: %d\nMédia: %.1f\n\n", 
        aluno.nome[menormed[x]], aluno.matricula[menormed[x]], aluno.mediam[menormed[x]]);
    }
    return 0;
}
