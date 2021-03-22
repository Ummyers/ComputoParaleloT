#include <stdio.h>

int mi_arreglo[] = {1,23,17,4,-5,100}; //Se inicializa el arreglo
int *ptr;

int main(void)
{
	int i;
	ptr = &mi_arreglo[0];
	/* apuntamos nuestro puntero
	al primer elemento del arreglo*/

	printf("Su dirección en memoria es: %p\n",&ptr);

	printf("\n\n");
	int *puntero; 

	*(ptr + 4) = 7; //Estoy estableciendo que en la posición 4 haya un 7 

	for (i = 0; i < 6; i++)
	{
		printf("mi_arreglo[%d] = %d \n", i, mi_arreglo[i]);
		//con el apuntador
		printf("ptr + %d = %d \n",i, *(ptr + i));
		puntero = ptr+i;
		//Para imprimir un puntero se usa %p
		// printf("Su dirección en memoria es: %p \n", &puntero); 
		// Se esta imprimiendo la dirección de memoria

		//Tenemos dos punteros apuntando a lo mismo
		//ptr y puntero: apuntan a lo mismo
		printf("El apuntador apunta a: %d \n",*puntero); 		
	}
	return 0;
}