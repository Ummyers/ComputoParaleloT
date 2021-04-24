/* Algoritmo de Knuth. 
* Abril, 2021
* Muñiz Patiño, Andrea
*/
#include <stdlib.h>
#include <stdio.h>

void ImprimirTablaKunth(int tablaKnuth[]);
void imprimirPatron();

int indice = 0;
//Tentativo numero de palabras del texto
int numWord = 0;
//Número de símbolos que tiene el patrón
int tamPatron = 0; 
//Número de símbolos que tiene el texto
int numSimbolos = 0;
char t; //para el texto
char p; //para el patron 
//Guardamos el texto 
char *texto;
//Guardamos el patron
char *patron;


FILE *pf; //Puntero para el texto
FILE *pfp; //Puntero para el patron


/* @brief pre procesa el patron y el texto
* 
*/
void preText(){
    //Pre-procesa el texto

    //Determina el número de palabras
    while ((t = getc(pf)) != EOF)
    {
        if ((t == ' ') || (t == ',') || (t == '.'))
            numWord++;
    }

    int numSim = fseek(pf, 0, SEEK_SET);
    //Contabiliza el número de símbolos del texto
    while ((t = getc(pf)) != EOF)
    {
        if (!((t == ',') || (t == '.')))
            numSimbolos++;
    }

    while ((p = getc(pfp)) != EOF)
    {
        tamPatron++;
    }
    printf("numWord: %d, tamPatron: %d, numSimbolos: %d \n", numWord, tamPatron, numSimbolos);
}

void extraerPatron(){
    //Se obtiene el patro del archivo se guarda en "patron"
    int i = 0;
    while ((p = getc(pfp)) != EOF)
    {
        *(patron + i) = p;
        i++;
    }
}

void auxiliarKnuth()
{
    int tablaKnuth[tamPatron];
    printf("\nTabla Auxiliar del algoritmo Knuth\n");

    //Se inicializa el arreglo con valores de -1
    for (int i = 0; i < tamPatron; i++)
    {
        tablaKnuth[i] = 0;
    }

    char simboloActual;
    char simboloSiguiente;
    for (int i = 0; i < tamPatron; i++)
    {
        simboloActual = *(patron + i);
        if (tablaKnuth[i] == 0)
        {
            // printf("Entra a posición %d a poner -1",i);
            tablaKnuth[i] == -1;
            for (int j = i + 1; j < tamPatron; j++)
            {
                simboloSiguiente = *(patron + j);
                if (simboloActual == simboloSiguiente)
                {
                    tablaKnuth[j] = i + 1;
                }
            }
        }
    }
    for (int i = 0; i < tamPatron; i++)
    {
        // tablaKnuth[i] = -1;
        printf("tablaKunth[%d] = %d\n", i, tablaKnuth[i]);
    }
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

    texto = (char*)malloc(numSimbolos* sizeof(char));
    patron = (char*)malloc(tamPatron * sizeof(char));

    // Colocamos el puntero al inicio del archivo
    int inicio = fseek(pfp,0,SEEK_SET);
    //el puntero pfp se mueve cero posiciones desde el incio.

    // extraerPatron();
    int i = 0;
    while ((p = getc(pfp)) != EOF)
    {       
        *(patron + i) = p;
        i++;
    }

    printf("El patron tiene tam: %d \n ", tamPatron);
    //imprimirPatron();
    for (int k = 0; k < tamPatron; k++)
    {
        printf(" %c ", *(patron + k));
    }

    // printf("%c", *(patron+1));

    // Colocamos el puntero al inicio del archivo del texto
    int inicioTe = fseek(pf, 0, SEEK_SET);
    //     //Obtenemos el texto

    printf("\n El numero de palabras %d", numWord);

    int j = 0;
    LOOP:while ((t = getc(pf)) != EOF){
    //     //Quita comas y puntos
        if ((t == ',') || (t == '.'))
        {
            *(texto + j) = ' ';
            goto LOOP;        
        }
        *(texto + j) = t; 
        j++;
    }
    
    //auxiliarKnuth();

    //Tabla auxiliar para el algoritmo Knuth
    int tablaKnuth[tamPatron];
    printf("\nTabla Auxiliar del algoritmo Knuth\n");

    //Se inicializa el arreglo con valores de -1
    for (int i = 0; i < tamPatron; i++)
    {
        tablaKnuth[i] = 0;
    }

    char simboloActual;
    char simboloSiguiente;
    for (int i = 0; i < tamPatron; i++)
    {
        simboloActual = *(patron + i);
        if (tablaKnuth[i] == 0)
        {
            // printf("Entra a posición %d a poner -1",i);
            tablaKnuth[i] == -1;
            for (int j = i + 1; j < tamPatron; j++)
            {
                simboloSiguiente = *(patron + j);
                if (simboloActual == simboloSiguiente)
                {
                    tablaKnuth[j] = i + 1;
                }
            }
        }
    }

    ImprimirTablaKnuth(tablaKnuth);

    //Liberando memoria
    free(texto);
    free(patron);

    //Cerrando archivos
    fclose(pf);
    fclose(pfp);

    return 0;
}

void ImprimirTablaKnuth(int tablaKnuth []){ 
    for (int i = 0; i < tamPatron; i++)
    {
        // tablaKnuth[i] = -1;
        printf("tablaKunth[%d] = %d\n", i, tablaKnuth[i]);
    }
}

/* @brief imprime el patron a buscar
*/
void imprimirPatron()
{
    printf("El patron tiene tam: %d \n", tamPatron);

    for (int k = 0; k < tamPatron; k++)
    {
        printf(" %c ", *(patron + k));
    }
    printf("\n");
}