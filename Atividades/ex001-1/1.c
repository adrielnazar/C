#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)

{
	setlocale(LC_ALL, "Portuguese");
    int x, escolha, cont;
    float valor, celciu, fahrenheit, reais, dolares, tes;

    do
    {
        
            printf("Digite o valor em Reais que irá ser convertido:\n");
            scanf("%f", &reais);
            printf("%.2f\n", reais);
            printf("Digite o valor do Dolar que vale um Real:\n");
            scanf("%f", &dolares);
            printf("%.2f\n", dolares);
            valor= reais/dolares;
            printf("%.2f\n", valor);
            printf("O valor de %.2f reais em Dolares é de %.2f", reais, valor);
        
        
        printf("\nQuer fazer outra converção?(1 para sim / 2 para nao)\n");
        scanf("%d", &cont);
    } while (cont == 1);
    
    return 0;
}
