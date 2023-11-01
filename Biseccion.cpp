#include <iostream>
#include <cmath>
#include<fstream>
#include<windows.h>
#include <string>

using namespace std;

float E;

double funcion(double x) {
	// Falta leer la funcion desde el archivo
/*	ifstream funcion("funcion.txt");
	double func;
	funcion >> func;
	cout << func;
    return func;*/
    return x*x*x-2*x*x-4*x+8;
    
}

void biseccion(double a, double b) {
	
	cout << "i		"<<"a		" << "	b			" << "f(a)			" << "f(b)			" << "c		" << "f(c)\n\n";
	
    if (funcion(a) * funcion(b) >= 0) {
        cout << "No puedes usar el método de bisección\n";
        return;
    }

    double c = a;
    int convergencia;
    
	ofstream file("tabla.txt");
	
    while ((b-a) >= E) {
    	convergencia++;
    	cout << convergencia << "	" << a << " |		" << b << " |		" << funcion(a) << " |		" << funcion(b) << " |	" << c << " |	" << funcion(c) << endl;
    	file <<  convergencia << "," << a << "," << b << "," << funcion(a) << "," << funcion(b) << "," << c << "," << funcion(c) << endl;
		
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
    
    cout << "\n> La raíz es: " << c;
    cout << "\n> El método converge a " << convergencia << " iteraciones.";
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
    
    a = -2.5;
    b= -1.5;
    E = 0.0001;
    biseccion(a, b);
    
    return 0;
}

