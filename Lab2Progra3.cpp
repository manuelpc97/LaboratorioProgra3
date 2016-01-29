#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

unsigned long long int factorial(int numero);
double euler(int numero);
double ladosTrapezio(double a1, double a2, double b1, double b2);
double altura(double lado1, double lado2, double lado3, double semi);
double area(double alt, double diagonal);
int main(int argc, char*argv[]){
	int opcion, numero;
	double a1=0.0,a2=0.0,b1=0.0,b2=0.0,c1=0.0,c2=0.0,d1=0.0,d2=0.0;
	double resp, lado1=0.0,lado2=0.0,lado3=0.0,lado4=0.0, diagonal=0.0, semi1=0.0, semi2=0.0;
	double alt1, alt2,alt3,alt4,alt5,alt6;

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
		cout<<"Ingrese las coordenadas de su primer punto"<<endl;
		cin>>a1;
		cin>>a2;

		cout<<"Ingrese las coordenadas de su segundo punto"<<endl;
                cin>>b1;
                cin>>b2;

		cout<<"Ingrese las coordenadas de su tercer punto"<<endl;
                cin>>c1;
                cin>>c2;

		cout<<"Ingrese las coordenadas de su cuarto punto"<<endl;
                cin>>d1;
                cin>>d2;

		
		
		
		if((a1==b1&&a1==c1)||(a1==c1&&a1==d1)||(b1==c1&&b1==d1)){
			cout<<"Tres numeros forman una linea, coordenadas incorrectas"<<endl;
		}else if((a2==b2&&a2==c2)||(a2==c2&&a2==d2)||(b2==c2&&b2==d2)){
			cout<<"Tres numeros forman una linea, coordenadas incorrectas"<<endl;
		}else{

		cout<<"Los puntos son: "<<endl;
		cout<<"("<<a1<<","<<a2<<")"<<endl;
		cout<<"("<<b1<<","<<b2<<")"<<endl;
		cout<<"("<<c1<<","<<c2<<")"<<endl;
		cout<<"("<<d1<<","<<d2<<")"<<endl;
		
		lado1=ladosTrapezio(a1,a2,b1,b2);
		lado2=ladosTrapezio(b1,b2,d1,d2);
		lado3=ladosTrapezio(a1,a2,c1,c2);
		lado4=ladosTrapezio(c1,c2,d1,d2);
		diagonal = ladosTrapezio(a1,b2,d1,d2);

		cout<<"Los lados del trapezoide miden: "<<endl;
		cout<<"Lado 1: "<<lado1<<endl;
		cout<<"Lado 2: "<<lado2<<endl;
		cout<<"Lado 3: "<<lado3<<endl;
		cout<<"Lado 4: "<<lado4<<endl;

		cout<<"LOs lados del triangulo 1 miden = "<<endl;
		cout<<"Lado 1: "<<lado1<<endl;
		cout<<"Lado2: "<<lado2<<endl;
		cout<<"Lado3: "<<diagonal<<endl;

		cout<<"LOs lados del triangulo 2 miden = "<<endl;
                cout<<"Lado 1: "<<lado3<<endl;
                cout<<"Lado2: "<<lado4<<endl;
                cout<<"Lado3: "<<diagonal<<endl;
		
		semi1=(lado1 +lado2+diagonal)/2;
		semi2=(lado3+lado4+diagonal)/2;
		cout<<"El semiperimetro del triangulo 1  es: "<<semi1<<endl;
		cout<<"El semiperimetro del triangulo 2  es: "<<semi2<<endl;
		cout<<"El perimetro del triangulo 1  es: "<<lado1+lado2+diagonal<<endl;
		cout<<"El perimetro del triangulo 2  es: "<<lado3+lado4+diagonal<<endl;

		alt1=altura(lado1, lado2, diagonal, semi1);
		alt2=altura(lado2, lado1, diagonal, semi1);
		alt3=altura(diagonal, lado2, lado1, semi1);
		alt4=altura(lado3, lado4, diagonal, semi2);
		alt5=altura(lado4, lado3, diagonal, semi2);
		alt6=altura(diagonal, lado4, lado3, semi2);

		cout<<"Las alturas del traingulo 1 son: "<<endl;
		cout<<"Altura 1: "<<alt1<<endl;
		cout<<"Altura 2: "<<alt2<<endl;
		cout<<"Altura 3: "<<alt3<<endl;

		cout<<"Las alturas del traingulo 2 son: "<<endl;
                cout<<"Altura 1: "<<alt4<<endl; 
                cout<<"Altura 2: "<<alt5<<endl;
                cout<<"Altura 3: "<<alt6<<endl;			

		cout<<"El area del trapezio es: "<<area(alt3, diagonal)+area(alt6,diagonal)<<endl;
}				
}
return 0;	
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

double ladosTrapezio(double a1, double a2, double b1, double b2){
	double medida=0;
	medida = sqrt((pow(a1-b1,2))+(pow(a2-b2,2)));
	return medida;
}

double altura(double lado1, double lado2, double lado3, double semi){
	double altura=0.0;

	altura=(2/lado1)*(sqrt(semi*(semi-lado1)*(semi-lado2)*(semi-lado3)));
	return altura;
}

double area(double alt, double diagonal){
	double ar;
	ar= (diagonal*alt)/2;
return ar;
}
