#include <stdio.h>
#include <stdlib.h>

int indice = 0;
int numWord = 0;
char c;

struct word{
	char pal[20]; 
	int veces;
};

FILE *pf2;
struct word *texto;

/* @brief Cuantas palabras tendrá
*
*/

void numWords(){
    while ((c = getc(pf2)) != EOF){
        if ((c == ' ') || (c == ',') || (c == '.')){
            numWord++;
        }
    }
}

/* @brief Imprime todas las palabras
*
*/
void imprimirTexto(){
    for (int k = 0; k <= numWord; k++){
        printf("Word %d: %s \n", k, texto[k].pal);
    }
}

int main(int argc, char const *argv[])
{
	FILE *pf; //Puntero para el archivo

	char *nombre = "Texto.txt";

    //Verifica que los apuntadores se inicien de forma correcta
    if (((pf = fopen(nombre, "rt")) == NULL) || ((pf2 = fopen(nombre, "rt")) == NULL))
    {
        puts("Error en la operación de apertura");
		return -1;
    }
    numWords();

    texto = (struct word *)malloc(numWord * sizeof(struct word));

    int j = 0;
    int i = 0;

	while ((c=getc(pf))!=EOF){ 
        //Quita comas y puntos
		if((c==' ')||(c==',')||(c=='.')){
            indice++;
            i = 0;
        }
        texto[indice].pal[i] = c;
        texto[indice].veces = 1;
        i++;
	}

    imprimirTexto();

    free(texto);
    fclose(pf);
    fclose(pf2);
	return 0;
}