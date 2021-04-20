#include <stdio.h>
#include <stdlib.h>

FILE *ff;
char* arch = "Texto.txt";  

struct word{
	char pal[20]; 
	int veces;
};

int main(int argc, char const *argv[])
{
	int c, n=0;
	int i, indice;
	FILE *pf; //Puntero para el archivo
	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}
	
	struct word texto[100];
	
	indice = 0;
	int j = 0;

	while ((c=getc(pf))!=EOF){ 
	i = 0;
		do{
			texto[indice].pal[i] = c;
			texto[indice].veces = 1;  
			i++;
		}while((c=getc(pf))!=' ');

	// 	printf("Index %d Palabra: %s \n", j, texto[j].pal);
	// 	j++;
	// 	index++;
	}
	fclose(pf);
	return 0;
}