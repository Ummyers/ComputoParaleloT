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

/* @brief Contabiliza las palabras del texto
*
*/

void numWords(){
    while ((c = getc(pf2)) != EOF){
        if (c == ' '){
            numWord++;
        }
    }
     numWord++;
    printf("El número de palabras es: %d \n", numWord);
}

/* @brief Imprime todas las palabras
*
*/
void imprimirTexto(){
    for (int k = 0; k < numWord; k++){
        printf("Word %d: %s \n", k, texto[k].pal);
    }
}

void imprimirTablaSimilitud(int tablaSimilitud [numWord][numWord]){
    for(int i = 0; i < numWord; i++){
        for (int j = 0; j < numWord; j++)
        {
            printf("%d ", tablaSimilitud[i][j]);
        }
        
    }

}

int main(int argc, char const *argv[])
{
	FILE *pf; //Puntero para el archivo

	char *nombre = "Texto1.txt";

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

	LOOP:while ((c=getc(pf))!=EOF){ 
        //Quita comas y puntos
		if((c==' ')||(c==',')||(c=='.')||(c== '\n')){
            indice++;
            i = 0;
            // printf("Leyó %c indice = %d i = %d\n",c, indice, i);
            if ((c == ',') || (c == '.'))
            {
                c = getc(pf);
            }
            goto LOOP;
        }else{
            texto[indice].pal[i] = c;
            texto[indice].veces = 1;
            i++;
        }	
    }

    imprimirTexto();

    //Tabla de similitud [renglon][columna]
    int tablaSimilitud [numWord][numWord];

    //Rellenamos con ceros! 
    for (int i = 0; i < numWord; i++)
    {
        for (int j = 0; j < numWord; j++)
        {
            tablaSimilitud[i][j] = 0;
        }
    }

    //---------Calculo de tabla de similitud
    char sim1, sim2;
    printf("\n Comparas %s con %s \n", texto[0].pal ,texto[2].pal);

    int pos = 0;
    int x = 0;

    for (int i = 0; i < numWord; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            do
            {
                if(i==j){
                    tablaSimilitud[i][j] = -2;
                }
                sim1 = texto[j].pal[pos];
                sim2 = texto[i].pal[pos];
                if (sim1 == sim2)
                {
                    tablaSimilitud[i][j]++;
                    printf("%c es igual que %c \n", sim1, sim2);
                }
                pos++;
            } while ((sim1 != '\0') && (sim2 != '\0'));
        pos = 0;
        }
        x++;
    }

    


    // imprimirTablaSimilitud(tablaSimilitud [numWord][numWord]);
    printf("\n Similitud entre %s y %s es: %d \n", texto[0].pal ,texto[2].pal, tablaSimilitud[2][0]);

    printf("--Inicia toda la matriz--\n");

    
    x = 0;
    for (int i = 0; i < numWord; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            printf("%d ", tablaSimilitud[i][j]);
        }
        printf("\n");
        x++;
    }

    //Liberando memoria y cerrando archivos
    free(texto);
    fclose(pf);
    fclose(pf2);
	return 0;
}