/*    Busqueda Paralela en C
* Asignación dinamica de memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 

//Apuntador arreglo 
int *arreglo;
int n;

//Metodo para imprimir el arreglo
void imprimir(){
	for(int i = 0; i < n; i++){
		printf(" %d ", *(arreglo + i));
	}
	printf("\n");
}

/* Metodo que rellena un arreglo 
con elementos pseudo-aleatorio
en el intervalo [0,99]
*/
void Rellenar(){
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		*(arreglo +i) = rand ()%100;
	}
}

void BBinariaParallel(int elemBuscado){

	omp_set_num_threads(n);
	printf(">>Busqueda Paralela \n Número de hilos es: %i y buscamos %i \n",n,elemBuscado);

	int idHilo;
	int bandera = 0;

	#pragma omp parallel private(idHilo)
	{
		idHilo = omp_get_thread_num();
		//printf("Número de hilo: %i \n",idHilo );
		if(*(arreglo + idHilo) == elemBuscado){
			bandera = 1;
			printf("El elemento se encuentra en la posición %i \n", idHilo);
		}
	}
	if(bandera==0){
		printf("@@El elemento no fue encontrado, BB\n");
	}
}

int main(int argc, char** argv){

	printf("Indica el número de elementos del arreglo: \n");
	scanf("%d",&n); 
	//Se asigna el tamaño de memoria suficiente para el arreglo
	arreglo = (int*)malloc(n*sizeof(int));
	Rellenar();
	imprimir();
	printf("----\n");

	//En la posición 1 siempre habrá un 7  
	*(arreglo + 1) = 7;
	//Para realizar pruebas

	int eBuscado; //Elemento a buscar 
	printf("¿Qué número quieres buscar en el arreglo?\n");
	scanf("%d", &eBuscado);
	BBinariaParallel(eBuscado);	
	return 0;
}