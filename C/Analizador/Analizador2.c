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
    // int n = 0;
    // char c;
	int i, index;
	FILE *pf; //Puntero para el archivo
    FILE *pf2;

	char *nombre = "Texto.txt";

	if((pf = fopen(nombre, "rt"))== NULL){
		puts("Error en la operación de apertura");
		return -1;
	}

    if ((pf2 = fopen(nombre, "rt")) == NULL)
    {
        puts("Error en la operación de apertura");
        return -1;
    }
    //Aproximamos cuantas palabras tendrá
    int numWord = 0; 
	while ((c=getc(pf2))!=EOF){
        if ((c == ' ') || (c == ',') || (c == '.'))
        {
            numWord++;
        }
    }

    //printf("El número de palabras aproximado es: %d", numPalabras);

	
	// struct word texto[200];
    struct word *texto; 
    texto = (struct word*)malloc(numWord*sizeof(struct word));
	
	index = 0;
	int j = 0;

	i = 0;
	while ((c=getc(pf))!=EOF){ 
        //Quita comas y puntos
        // printf("Caracter leido %c \n",c);
		if((c==' ')||(c==',')||(c=='.')){
            // printf("Se leyó un espacio, como o caracter \n");
            index++;
            i = 0;
            //Verifica que no es el fin de archivo
            // if((c=getc(pf)) == EOF)
                // break; 
        }
        texto[index].pal[i] = c;
        texto[index].veces = 1;
        i++;
	}
    
    for (int k = 0; k <= numWord; k++)
    {
        if(texto[k].veces == 0)
            break; 
        printf("Index %d Palabra: %s \n", k, texto[k].pal);
    }

    fclose(pf);
	return 0;
}