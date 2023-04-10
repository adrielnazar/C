#include <stdio.h>
#include <stdlib.h>
#include "sucessor.h"

int main(int argc, char const *argv[]){

    int x;

    printf("Valor para calcular: ");
    scanf("%d",&x);

    printf("\n O sucessor � %d", sucessor(x));

    printf("\n O antecessor � %d", antecessor(x));

    return 0;
}
