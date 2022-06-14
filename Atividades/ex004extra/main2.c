#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "calculo.h"

int main(int argc, char const *argv[])

{
	setlocale(LC_ALL, "Portuguese");
    char cont;
    int escolha;
    float celciu, reais, dolares;

    do
    {
        printf("Qual converção você quer usar agora?\nDigite '1' se for de Celsius para Fahrenheit ou '2' se for de Real para Dólar:\n");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            printf("Digite o valor em Celcius que irá ser convertido:\n");
            scanf("%f", &celciu);
            printf("O valor de %.1fº Ceucius em Fahrenheit é de %.1fº", celciu, fahrenheit(celciu));
        }

        else if (escolha == 2) {
            printf("Digite o valor em Reais que irá ser convertido:\n");
            scanf("%f", &reais);
            printf("Digite o valor do Dolar que vale um Real:\n");
            scanf("%f", &dolares);
            printf("O valor de R$%.2f reais em Dolares é de $%.2f", reais, valor(reais, dolares));
        }
        
        else if (escolha != 1 && escolha != 2) {
            continue;
        }
        printf("\nQuer fazer outra converção?(s/n)\n");
        scanf("%s", &cont);
        system("pause");
        system("cls");
    } while (cont == 's');
    
    return 0;
}

