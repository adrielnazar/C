#include <stdio.h>
#include <stdlib.h>
#include "sucessor.h"

int main(void){

    int x;

    printf("Valor para calcular: ");
    scanf("%d",&x);

    printf("\n O sucessor é %d", sucessor(x));

    printf("\n O antecessor é %d", antecessor(x));

    return 0;
}

