#include <stdio.h>
#include <stdlib.h>

int main()

{
    char cont;
    int x, escolha;
    float real, dolar, valor, celciu, fahrenheit;

    do
    {
        cont == 0;
        setlocale(LC_ALL, "Portuguese");
        printf("Qual convercao você quer usar agora?\nDigite '1' se for de Celsius para Fahrenheit ou '2' se for de Real para Dólar:/n");
        scanf("%d", &escolha);
        
         if (escolha == 1) {
            printf("Digite o valor em Celcius que ira ser convertido: ");
            scanf("%f", &celciu);
            fahrenheit = celciu*1,8 + 32;
            printf("O valor de %f Ceucius em Fahrenheit eh de %f", &celciu, &fahrenheit);
        }

        if (escolha == 2) {
            printf("Digite o valor em Reais que ira ser convertido: ");
            scanf("%f", &real);
            printf("Digite o valor do Dolar que vale um Real: ");
            scanf("%f", &dolar);
            valor= real/dolar;
            printf("O valor de %f reais em Dolares eh de %f", &real, &dolar);
        }
        
        else continue;
        printf("Quer fazer outra convercao?(s/n)\n");
        scanf("%c", &cont);
    } while (cont == "s");
    
    return 0;
}
