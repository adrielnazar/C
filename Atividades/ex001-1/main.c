#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)

{
	setlocale(LC_ALL, "Portuguese");
    char cont;
    int x, escolha;
    float valor, celciu, fahrenheit, reais, dolares;

    do
    {
        printf("Qual converção você quer usar agora?\nDigite '1' se for de Celsius para Fahrenheit ou '2' se for de Real para Dólar:\n");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            printf("Digite o valor em Celcius que irá ser convertido:\n");
            scanf("%f", &celciu);
            fahrenheit = celciu*1.8 + 32;
            printf("O valor de %.1f Ceucius em Fahrenheit é de %.1f", celciu, fahrenheit);
        }

        else if (escolha == 2) {
            printf("Digite o valor em Reais que irá ser convertido:\n");
            scanf("%f", &reais);
            printf("Digite o valor do Dolar que vale um Real:\n");
            scanf("%f", &dolares);
            valor= reais/dolares;
            printf("O valor de %.2f reais em Dolares é de %.2f", reais, valor);
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
