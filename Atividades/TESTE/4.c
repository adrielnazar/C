#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()

{
	setlocale(LC_ALL, "Portuguese");
    char cont;
    int x, escolha;
    float real, dolar, valor, celciu, fahrenheit;

    do
    {
        cont == 0;
        setlocale(LC_ALL, "Portuguese");
        printf("Qual conver��o voc� quer usar agora?\nDigite '1' se for de Celsius para Fahrenheit ou '2' se for de Real para D�lar:/n");
        scanf("%d", &escolha);
        
         if (escolha == 1) {
            printf("Digite o valor em Celcius que ir� ser convertido: ");
            scanf("%f", &celciu);
            fahrenheit = celciu*1,8 + 32;
            printf("O valor de %f Ceucius em Fahrenheit � de %f", &celciu, &fahrenheit);
        }

        if (escolha == 2) {
            printf("Digite o valor em Reais que ir� ser convertido: ");
            scanf("%f", &real);
            printf("Digite o valor do Dolar que vale um Real: ");
            scanf("%f", &dolar);
            valor= real/dolar;
            printf("O valor de %f reais em Dolares � de %f", &real, &dolar);
        }
        
        else continue;
        printf("Quer fazer outra conver��o?(s/n)\n");
        scanf("%c", &cont);
    } while (cont == "s");
    
    return 0;
}
