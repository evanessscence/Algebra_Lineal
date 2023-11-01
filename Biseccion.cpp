#include <iostream>
#include <cmath>
#include<fstream>
#include<windows.h>
#include <string>

using namespace std;

float E;

double funcion(double x) {
	
/*	ifstream funcion("funcion.txt");
	double func;
	funcion >> func;
	cout << func;
    return func;*/
    return x*x*x*x-5*x*x*x+0.5*x*x-11*x+10;
    
}

void biseccion(double a, double b) {
	
	cout << "a		" << "	b			" << "f(a)			" << "f(b)			" << "c		" << "f(c)\n\n";
	
    if (funcion(a) * funcion(b) >= 0) {
        cout << "No puedes usar el método de bisección\n";
        return;
    }

    double c = a;
	ofstream file("tabla.txt");
    while ((b-a) >= E) {
    	
    	cout << a << " |		" << b << " |		" << funcion(a) << " |		" << funcion(b) << " |	" << c << " |		" << funcion(c) << endl;
    	file << a << "," << b << "," << funcion(a) << "," << funcion(b) << "," << c << "," << funcion(c) << endl;
		
    	
        // Encuentra el punto medio
        c = (a+b)/2;
        // Verifica si el punto medio es la raíz
        if (funcion(c) == 0.0)
        {
        	cout << "El punto medio no es la raíz (" << funcion(c) << ")" << endl;
        	break;
		}        
		
        // Decide el lado para repetir los pasos
        else if (funcion(c)*funcion(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "\nLa raíz es: " << c;
}

int main() {
	
	 SetConsoleOutputCP(CP_UTF8);
    // Valores iniciales supuestos
    float a, b;
  /*  
    cout<<"Ingrese el valor de [a]: ";
    cin>>a;
    cout<<"Ingrese el valor de [b]: ";
    cin>>b;
    cout<<"Defina la precisión requerida E: ";
    cin>>E;
    */
    
    a = 0.55;
    b= 1.1;
    E = 0.0001;
    biseccion(a, b);
    
    
    return 0;
}

