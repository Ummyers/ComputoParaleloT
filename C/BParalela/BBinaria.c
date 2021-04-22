/*Busqueda "Binaria" en C, por anexar*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 

int	tam = sizeof(arreglo)/4; //Tamaño de memoria entre 4 por que son bytes
int arreglo [100];


//Metodo para imprimir el arreglo
void imprimir(){
	for(int i = 0; i < tam; i++){
		printf("%i, ",arreglo[i] );
	}
	printf("\n");
}

//Metodo que rellena un arreglo pseudo-aleatorio
void Rellenar(){
	srand(time(NULL));
	for(int i = 0; i < tam; i++){
		arreglo[i] = rand ()%100;
	}
	printf("\n");
}

void BBinariaParallel(int elemBuscado){

	omp_set_num_threads(tam);
	printf(">>Busqueda Paralela \n Número de hilos es: %i y buscamos %i \n",tam,elemBuscado);

	int idHilo;
	int bandera = 0;

	#pragma omp parallel private(idHilo)
	{
		idHilo = omp_get_thread_num();
		//printf("Número de hilo: %i \n",idHilo );
		if(arreglo[idHilo]==elemBuscado){
			bandera = 1;
			printf("El elemento se encuentra en la posición %i \n", idHilo);
		}
	}

	if(bandera==0){
		printf("@@El elemento no fue encontrado, BBinaria\n");
	}
}

int main(int argc, char** argv){

	Rellenar();
	imprimir();
	printf("----\n");
	arreglo[7] = 7;
	imprimir();
	printf("Tam: %i \n",tam);
	int eBuscado; //Elemento a buscar 
	printf("¿Qué número quieres buscar en el arreglo?\n");
	scanf("%d", &eBuscado);
	BBinariaParallel(eBuscado);	
	return 0;
}
