/* No ejecutar que se muere la compu
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	void *p;
	int i;
	long m = 0;

	for(int i = 1; ;i++){
		p = malloc(1000);
		if (p == NULL) break;
		m+= 1000;
	}

	printf("\n Total de memoria asignada %ld \n",m);
	printf("Numero de Kilobyte conseguidos: %ld \n",m/1000);
	return 0;

}
