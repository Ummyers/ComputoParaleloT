#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	char cad[121];
	char *ptr;
	int lon;

	puts("\n Introducir cadena");
	gets(cad);

	lon = strlen(cad);
	ptr = (char*)malloc((lon+1)*sizeof(char));

	strcpy(ptr,cad); /* Copia lo que hay en cad
						a nueva área de memoria apuntada por ptr
					*/

	printf("ptr = %s\n",ptr);
	/* Estas imprimiendo lo que 
	esta en la memoria apuntado por ptr 
	*/
	// printf("ptr = %s \n",&ptr); 
	//   &apuntador es la dirección tal cual :) 
	free(ptr);

}

