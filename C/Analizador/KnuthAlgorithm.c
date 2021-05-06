/* Algoritmo de Knuth. 
* Abril, 2021, Mayo
* Muñiz Patiño, Andrea
*/
#include <stdlib.h>
#include <stdio.h>

//Declarando funciones
void imprimirTablaKnuth(int tablaKnuth[]);
void imprimirPatron();
void tablaKnuth2(int tableKnuth[]);
void imprimirTexto();

int indice = 0;

//Numero de palabras del texto
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

//APuntadores para el algoritmo de Knuth
char *patronTabla; 
int *tablaK; 


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


    // -------------extraerPatron------------
    int i = 0;
    while ((p = getc(pfp)) != EOF)
    {       
        *(patron + i) = p;
        i++;
    }
    // -------------extraerPatron------------

    printf("El patron tiene tam: %d \n ", tamPatron);

    //---------------imprimirPatron------------
    for (int k = 0; k < tamPatron; k++)
    {
        printf(" %c ", *(patron + k));
    }
    //---------------imprimirPatron------------


    // Colocamos el puntero al inicio del archivo del texto
    int inicioTe = fseek(pf, 0, SEEK_SET);
    
    
    //------------Obtenemos el texto----------
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
    //------------Obtenemos el texto----------



    //-----------------auxiliarKnuth-------------------

    //Tabla auxiliar para el algoritmo Knuth
    int tablaKnuth[tamPatron];
    printf("\nTabla Auxiliar del algoritmo Knuth\n");

    //Se inicializa el arreglo con valores de -1
    for (int i = 0; i < tamPatron; i++){
        tablaKnuth[i] = 0;
    }

    char simboloActual;
    char simboloSiguiente;
    for (int i = 0; i < tamPatron; i++){
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

    //-----------------auxiliarKnuth-------------------


    // printf("--Llamando a ImprimirTablaKnuth--\n");
    // imprimirTablaKnuth(tablaKnuth);

    //-----------------Tabla de Knuth---------------------
    // tablaKnuth2(tablaKnuth);

    //Tiene el patron iniciado en la posición 1
    patronTabla = (char *)malloc((tamPatron + 1) * sizeof(char));
    //Indica cuantas posiciones se movera el apuntador j_Indu
    tablaK = (int *)malloc((tamPatron + 1) * sizeof(int));

    *(patronTabla + 0) = ' ';
    *(tablaK + 0) = 0;

    for (int iTK = 1; iTK < tamPatron + 1; iTK++)
    {
        //Caracteres en posiciones correctas? (Segun la facilidad del algoritmo de Knuth)
        *(patronTabla + iTK) = *(patron + iTK - 1);
        //Valores de la tabla de Knuth
        *(tablaK + iTK) = tablaKnuth[iTK - 1];
    }

    for (int k = 0; k < tamPatron+1; k++)
    {
        printf(" %c ", *(patronTabla + k));
    }
    printf("\n");

    for (int k = 0; k < tamPatron+1; k++)
    {
        printf(" %d ", *(tablaK + k));
    }
    printf("\n");

    //-------------------Tabla de Knuth------------------



    //----------Implementación del algoritmo de Knuth-----------------

    //imprimirTexto();
    /* La variable i itera en el texto
    *   La variable j itera en el patron
    * Se inician los valores en cero dado el algoritmo 
    */

    int i_Indu = 0;
    int j_Indu = 0;

    /* Mientras no se termine el texto o se encuentre una coincidencia
    *   seguirá buscando el patron
    *
    */

   printf("\n----Inicia Algoritmo de Knuth----\n");
    char ch_Texto, ch_patron;

   while(i_Indu < numSimbolos){
       if(j_Indu == tamPatron){
           printf("El patrón se encuentra en el intervalo [%d,%d] del texto \n",i_Indu-tamPatron,i_Indu);
           break;
       }else{
           ch_patron = *(patronTabla + j_Indu + 1);
           ch_Texto = *(texto + i_Indu);
        //    printf("Se compara <%c> del texto con <%c> del patron \n",ch_Texto, ch_patron);

           if(ch_patron == ch_Texto){
            //    printf("@@Se incremento i_Indu y j_Indu\n");
               j_Indu++;
           }else{
               j_Indu = *(tablaK + j_Indu);
           }
           i_Indu++;
       }
   }

   printf("Valor de i_Indu %d \n",i_Indu);
   printf("Valor de j_Indu %d \n", j_Indu);

   //----------Implementación del algoritmo de Knuth-----------------

  
   //Liberando memoria
   free(texto);
   free(patron);

   //Cerrando archivos
   fclose(pf);
   fclose(pfp);

   return 0;
}

void imprimirTexto()
{
    printf("----Imprimiendo Texto----\n");

    for (int k = 0; k < numSimbolos + 1; k++)
    {
        printf("%c", *(texto + k));
    }
    printf("\n----Imprimiendo Texto----");

    printf("\n");

}

void imprimirTablaKnuth(int tablaKnuth[])
{
    for (int i = 0; i < tamPatron; i++)
    {
        // tablaKnuth[i] = -1;
        printf("tablaKunth[%d] = %d\n", i, tablaKnuth[i]);
    }
}

// Función que re- coloca los valores para "que las cuentas sean fáciles"
void tablaKnuth2(int tablaKnuth[]){

    //Tiene el patron iniciado en la posición 1 
    patronTabla = (char *)malloc((tamPatron + 1) * sizeof(char));
    //Indica cuantas posiciones se movera el apuntador j_Indu
    tablaK = (int *)malloc((tamPatron + 1) * sizeof(int));

    *(patronTabla + 0) = ' ';
    *(tablaK + 0) = 0;

    for (int iTK = 1; iTK < tamPatron + 1; iTK++)
    {
        //Caracteres en posiciones correctas? (Segun la facilidad del algoritmo de Knuth)
        *(patronTabla + iTK) = *(patron + iTK - 1 );
        //Valores de la tabla de Knuth 
        *(tablaK + iTK) =  tablaKnuth[iTK-1];
    }

    for (int k = 0; k < tamPatron; k++)
    {
        printf(" %c ", *(patronTabla + k));
    }
    printf("\n");

    for (int k = 0; k < tamPatron; k++)
    {
        printf(" %c ", *(tablaK + k));
    }
    printf("\n");
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