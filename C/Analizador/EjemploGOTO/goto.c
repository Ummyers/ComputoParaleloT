#include <stdio.h>

int main(){
    int a = 0;

//Como usar el goto

LOOP:do
    {
        if (a == 15)
        {
            /* skip the iteration */
            a = a + 1;
            goto LOOP;
        }

        printf("value of a: %d\n", a);
       a++;

    } while (a < 20);
}