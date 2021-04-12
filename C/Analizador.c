#include <stdio.h>
#include <stdlib.h>

FILE *ff;

char* arch = "Texto.txt"; //El archivo que se abrira 

/* Estructura palabra
* char pal: Tiene la palabra 
* Int veces: el numero de apariciones de la cadena pal 
*/
struct pal{
	char pal[20]; 
	/* 9 es el promedio de longitud de una palabra en 
	español
	*/
	int veces;
};

// strlne:: longitud de una cadena 
// strcat:: Concatena la cadena 1 con la cadena 2
// strcmp:: Para saber si dos cadenas son iguales 

int main(int argc, char const *argv[])
{
	struct pal palabra = {"cadena",1};
	printf("Valor de veces: %d \n", palabra.veces);
	printf("Valor de pal: %s \n", palabra.pal );
	// printf("%s\n", );

	struct pal texto[100];
	struct pal otra = {"Otra",78}; 
	texto[0] = otra; 

	int op = 1;
	char palabraAgrega[20];
	puts("¿Qué palabra quieres agregar?");
	int index = 0;
	do{
		puts("Proporcina la palabra");
		// gets(palabraAgrega);
		scanf("%s", palabraAgrega);
		// %s - Vamos recibir una cadena de carácteres
		struct pal newPal;
		//texto[index] = newPal;
		int i = 0;
		while(palabraAgrega[i] != '\0'){
			texto[index].pal[i] = palabraAgrega[i];
			i++; 
		}
		texto[index].veces = 1;
		index++;
		puts("¿Quieres seguir agregando palabras?");
		scanf("%d", &op);
	}while(op == 1);

	printf("En el arreglo: %s \n", texto[0].pal);
	printf("Inicia for: \n");
	for (int i = 0; i < 100; ++i)
	{
		if(texto[i].veces == 0){
				break;
		}
		printf("Palabra: \" %s \" en la posición %i \n", texto[i].pal, i);
	
	}

	int c, n=0;
	FILE* pf; //Puntero para el archivo
	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}
	//mientras no se llegue al fin del documento
	while ((c=getc(pf))!=EOF){ 
		if(c=='\n'){
			n++;
			printf("\n");
		}else{
			putchar(c);
		}
	}



	fclose(pf);
	return 0;
}