#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t timer = time(NULL);
    printf("%s", ctime(&timer));
    struct tm *dt_hr_atual;
    time_t segundos;
    time(&segundos);
    dt_hr_atual = localtime(&segundos);
    printf("Dia atual %d \n", dt_hr_atual->tm_mday);
    return 0;
}


//gilsonsantospr@hotmail.com