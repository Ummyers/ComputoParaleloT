#include <stdio.h>
#include <stdlib.h>

FILE *ff;
//si no existe el archivo y se quiere escribir se crea el documento
char* arch = "Texto.txt";  
int main(int argc, char const *argv[])
{
	int c, n=0;
	FILE* pf; //Puntero para el archivo
	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}
	/* Cuenta cuantas lineas tiene el documento	
	*/
	
	//mientras no se llegue al fin del documento
	while ((c=getc(pf))!=EOF){ 
		if(c=='\n'){
			n++;
			printf("\n");
		}else{
			putchar(c);
		}
	}
	printf("\nEl número de lineas es: %d \n",n);
	fclose(pf);
	return 0;
}