#include <stdio.h>
#include <stdlib.h>
int main() {
    char *c; /* o ponteiro para o espaço alocadi*/

    /*aloco oum único byte de memória*/
    c = (char *)malloc(1);

    /* vajo se consegue alocar*/
    if (!c) {
        printf("Não consegue alocar a memória\n");
        exit(1);
    }

    /* carrego um valor na região da memória alocada*/
    *c = 'd';

    /*escrevo esse valor*/
    printf("%c\n",*c);

    /*libero a memória alocada*/
    free(c);
}