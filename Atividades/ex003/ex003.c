#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    float x = 5.4;
    float arredondar_pbaixo, arredondar_pcima;

    floor(x);
    ceil(x);

    arredondar_pbaixo = floor(x);
    arredondar_pcima = ceil(x);

    int y = pow(3,2);

    printf("Valor para baixo %.0f \n", floor(x));
    printf("Valor para cima %.0f \n", arredondar_pcima);
    printf("Exponencial %d \n", y);
    //printf("Valor para cima %.0f \n", x);

    float f = atof("10.7");

    printf("%.2f\n", f);

    srand(5);

    for (x = 1 ; x <= 10; x++)
    {
        printf("Numero %d \n", rand());
    }
    

    printf("Numero Aleatorio %d %d %f \n", 2, rand(), f);

    return 0;
}
