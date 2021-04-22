#include <stdio.h>
#include <stdlib.h>

FILE *ff;
char* arch = "Text.txt"; //Sino
int main(int argc, char const *argv[])
{
	printf("Leyendo archivo...\n");
	if((ff = fopen(arch, "a"))==NULL){
		puts("Error al abrir el archivo para escribir.");
		exit(-1);
	}
	char cadena[] = "\n Linea...";
	fputs(cadena,ff);
	// printf("Po que no lo hace?\n");
	//Pues por que lo tenías en modo solo lectura -.-
	fclose(ff);
	return 0;
}