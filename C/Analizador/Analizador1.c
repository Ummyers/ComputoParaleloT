#include <stdio.h>
#include <stdlib.h>

FILE *ff;
//si no existe el archivo y se quiere escribir se crea el documento
char* arch = "Texto.txt";  

struct word{
	char pal[20]; 
	int veces;
};

// void leerPalabra(){
// int i, index, c;
// 	i = 0;
// 		while ((c=getc(pf))!=' '){ 
// 			texto[index].pal[i] = c;
// 			i++;
// 		}
// 		index++;
// }

int main(int argc, char const *argv[])
{
	int c, n=0;
	int cP; 
	int i, index;
	FILE* pf; //Puntero para el archivo
	FILE* pg;
	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}
	/* Cuenta cuantas lineas tiene el documento	
	*/
	struct word texto[100];
	//mientras se lea un caracter
	index = 0;

	/*
	Con esto no hay violación de acceso a memoria
	*/
	while ((cP=getc(pf))!=EOF){ 
	// puts("Lol");
	i = 0;
		while (((c=getc(pf))!=' ')&&((cP=getc(pf))!=EOF)){ 
			texto[index].pal[i] = c;
			texto[index].veces = 1;
			i++;
		}
		index++;
	}

	for (int i = 0; i < 100; i++)
	{
		if(texto[i].veces == 0){
			break;
		}
		printf("Index %d Palabra: %s \n", i, texto[i].pal);
	}


	fclose(pf);
	return 0;
}