#include <iostream>
#include <cmath>
#include<fstream>
#include<windows.h>
#include <string>
#include<conio.h>

using namespace std;

float E;

// Importar la librería desde el archivo en C
void biseccion(double a, double b) {
	
/*	cout << "i		"<<"a		" << "	b			" << "f(a)			" << "f(b)			" << "c		" << "f(c)\n\n";*/
	ofstream resultado("resultado.txt");
	
    if (funcion(a) * funcion(b) >= 0) {
        cout << "No puedes usar el método de bisección\n";
        resultado << "No puedes usar el método de bisección\n";
        return;
    }

    double c = a;
    int convergencia;
    
	ofstream file("tabla.txt");
	
	
    while ((b-a) >= E and (convergencia<100)) {
    	convergencia++;
    /*	cout << convergencia << "	" << a << " |		" << b << " |		" << funcion(a) << " |		" << funcion(b) << " |	" << c << " |	" << funcion(c) << endl;*/
    	file <<  convergencia << "," << a << "," << b << "," << funcion(a) << "," << funcion(b) << "," << c << "," << funcion(c) << endl;
		
        // Encuentra el punto medio
        c = (a+b)/2;
        // Verifica si el punto medio es la ra�z
        if (funcion(c) == 0.0)
        {
        	cout << "El punto medio no es la ra�z (" << funcion(c) << ")" << endl;
        	break;
		}        
		
        // Decide el lado para repetir los pasos
        else if (funcion(c)*funcion(a) < 0)
            b = c;
        else
            a = c;
    }
    
    if (convergencia == 100)
    {
        cout << "No se encontró la solución en " << convergencia << " iteraciones.";
        resultado << "No se encontró la solución en " << convergencia << " iteraciones.";
        return;
    }
    
    cout << "\n> La raíz es: " << c;
    cout << "\n> El método converge en " << convergencia << " iteraciones.";
    resultado <<  "\n> La raíz es: " << c << "\n> El método converge a " << convergencia << " iteraciones.";
    getch();
}

int main() {
	
	 SetConsoleOutputCP(CP_UTF8);
    system("COLOR F0");

    float a, b;

    ifstream at("a.txt");
    ifstream bt("b.txt");
    ifstream et("e.txt");
    
    at >> a;
    bt >> b;
    et >> E;

    biseccion(a, b);
    
    return 0;
}

