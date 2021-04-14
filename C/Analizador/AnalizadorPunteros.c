#include <stdio.h>
#include <stdlib.h>

FILE *ff;
//si no existe el archivo y se quiere escribir se crea el documento
char* arch = "Texto.txt";  

struct word{
	char pal[20];
	int veces;
};

int main(int argc, char const *argv[])
{
	int c, n = 0;
	int cP; 
	int i, index;
	FILE* pf; //Puntero para el archivo
	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}

	char prueba, prueba2;
	prueba = getc(pf);
	printf("Prueba tiene: %c\n",prueba);
	prueba2 = getc(pf);
	printf("Prueba tiene: %c\n",prueba2);
	fclose(pf);
	return 0;
}					