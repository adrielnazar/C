#include <stdio.h>
#include <locale.h>

typedef struct{
    int hora, min, sec;
}Hora;

typedef struct{
    int dia, mes, ano;
}Date;

typedef struct{
    Hora horario;
    Date data;
    char texto[300]
}Informa;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    Informa Informacao;
    int retorno = -1;

    do{
        printf("Escreva o horário do compromisso no formato h m s:");
        fflush(stdin);
        retorno = scanf("%d%d%d", &Informacao.horario.hora, &Informacao.horario.min, &Informacao.horario.sec);
        if (retorno == 0 || Informacao.horario.hora > 23 || Informacao.horario.hora < 0 || Informacao.horario.min > 60 || Informacao.horario.min < 0 || Informacao.horario.sec > 60 || Informacao.horario.sec < 0)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);
    
    do{
        printf("Escreva a data do compromisso no formato dd mm aaaa: ");
        fflush(stdin);
        retorno = scanf("%d%d%d", &Informacao.data.dia, &Informacao.data.mes, &Informacao.data.ano);
        if (retorno == 0 || Informacao.data.dia > 31 || Informacao.data.dia < 0 || Informacao.data.mes > 12 || Informacao.data.mes < 0 || Informacao.data.ano > 2050 || Informacao.data.ano < 0)
        {
            system("cls");
            printf("Escreva em um formato valido!\n");
            retorno = 0;
        }
    } while (retorno == 0);
    
    
    printf("Escreva a descrição do compromisso:");
    fflush(stdin);
    fgets(Informacao.texto, 300, stdin);

    printf("Horário: %d:%d:%d \nData: %d/%d/%d \nDescrição: %s", 
    Informacao.horario.hora, Informacao.horario.min, Informacao.horario.sec,
    Informacao.data.dia, Informacao.data.mes, Informacao.data.ano,
    Informacao.texto);
    return 0;
}


