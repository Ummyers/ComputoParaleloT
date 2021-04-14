#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;
   if ((fptr = fopen("Texto.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &num);

   printf("Value of n=%d \n", num);
   char c;
   while ((c = getc(fptr)) != EOF)
    {
        if(c == ' ')
        printf("\n");

        printf("%c ", c);
    }

    fclose(fptr);

    return 0;
   }
