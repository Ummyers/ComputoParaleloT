/* Algoritmo de Knuth. 
* Abril, 2021
* Muñiz Patiño, Andrea
*/

#include <stdio.h>
#include <stdlib.h>

int indice = 0;

//Tentativo numero de palabras del texto
int numWord = 0;
int tamPatron = 0; 
char t; //para el texto
char p; //para el patron
int tamPatronL;
    
//Guardamos el texto
char *texto;
//Guardamos el patron
char* patron;

FILE *pf; //Puntero para el texto
FILE *pfp; //Puntero para el patron

/* @brief imprime el patron a buscar
*/
void imprimirPatron(){
    tamPatronL = ((sizeof(patron)) / 2) + 1;
    // printf("El patron tiene tam: %d \n",tamPatronL);
    for (int k = 0; k < tamPatronL; k++)
    {
        printf(" %c ", *(patron + k));
    }
    printf("\n");
}

/* @brief pre procesa el patron y el texto
* 
*/
void preText(){
    while ((t = getc(pf)) != EOF)
    {
        if ((t == ' ') || (t == ',') || (t == '.'))
            numWord++;
    }
    while ((p = getc(pfp)) != EOF)
    {
        tamPatron++;
    }
    printf("numWord: %d, tamPatron: %d \n", numWord, tamPatron);
}



int main(int argc, char const *argv[])
{
	char *nombre = "Texto.txt";
    char *patron = "Patron.txt";

    //Verifica que los apuntadores se inicien de forma correcta
    if (((pf = fopen(nombre, "rt")) == NULL) || ((pfp = fopen(patron, "rt")) == NULL))
    {
        puts("Error en la operación de apertura");
		return -1;
    }
    //Para utilizar la memoria suficiente y necesaria
    preText();

    texto = (char*)malloc(numWord* sizeof(char));
    patron = (char*)malloc(tamPatron* sizeof(char));

    // Colocamos el puntero al inicio del archivo
    int inicio = fseek(pfp,0,SEEK_SET);
    //el puntero pfp se mueve cero posiciones desde el incio.

    int i = 0;
    while ((p = getc(pfp)) != EOF)
    {
        *(patron + i) = p;
        // printf("%c",p);
        i++;
    }

    
    imprimirPatron();
    //Liberando memoria
    free(texto);
    free(patron);
    //Cerrando archivos
    fclose(pf);
    fclose(pfp);

    return 0;
}