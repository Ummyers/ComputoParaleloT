#include<iostream> //Biblioteca principal 

using namespace std; 
/* Sirve para no tener que hacer lo siguiente
* std::cout<<
*/

int main(){
	cout<<"Hola mundo :)"<<endl; //Salto de linea 
	// \n tambien sirve
	//Imprime en pantalla

	int numero = 15; 
	cout<<numero<<endl;
	float num = 12.5;
	cout<<num<<endl;
	double d = 12.5534;
	char letra = 'b';
	cout<<letra<<endl;

	//lectura de datos en C++
	int num_Entrada;
	cout<<"Digita un numero\n";
	cin>>num_Entrada;
	cout<<"Número es:"<<num_Entrada<<endl;
	cout<<"La multiplicación es: "<<num_Entrada*2<<endl;

	//Para palabras:
	char sexo[10];
	cout<<"Dime tu nombre\n";
	cin>>sexo;
	cout<<"El nombre fue  "<<sexo<<endl;
	return 0;
}