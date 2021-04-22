#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	double *ad;
	int n;
	printf("número de elementos del array; \n");
	scanf("%d",&n); //Lo guardas en la dirección de memoria de n!
	ad = (double*)malloc(n*sizeof(double));
	//printf("tamño de memoria? %ld \n",sizeof(ad));
	//imprime 8 siempre

	// printf("El tamaño de short (entero corto), es: %d\n", sizeof(short));
	// printf("El tamaño de int (entero), es: %d\n", sizeof(int));
	// printf("El tamaño de long (entero largo), es: %d\n", sizeof(long));
	// printf("El tamaño de double, es: %d\n", sizeof(double));
	int i = 4; 
	*(ad+i) = 18;
	for (i = 0; i < n; i++)
	{
		printf("ad + %d = %d\n",i, *(ad + i));

	}


}