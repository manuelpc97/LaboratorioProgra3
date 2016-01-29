#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

unsigned long long int factorial(int numero);
double euler(int numero);

int main(int argc, char*argv[]){
	int opcion;
	int numero;
	double resp;

	cout<<"Ingrese la operacion que desea realizar"<<endl;
	cout<<"1.- Ejercicio 1"<<endl;
	cout<<"2. Ejercicio 2"<<endl;
	cin>>opcion;

	if(opcion==1){
		cout<<"Ingrese un numero para calcular el numero de Euler"<<endl;
		cin>>numero;
		resp = euler(numero);
		cout<<"El numero seria: "<<resp<<endl;
	}else if(opcion==2){
		
	}else{

	}	
}

unsigned long long int factorial(int numero){
	unsigned long long int resultado=1;

	for(int i = 1; i<=numero;i++){
		resultado*=i;
	}

	return resultado;
}

double euler(int numero){
	int limite = 22;
	double respuesta=1.0;

	for(int i = 1; i<=limite;i++){
		respuesta+=(pow(numero,i))/(factorial(i));
	}
return respuesta;	
}
