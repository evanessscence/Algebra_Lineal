#include <iostream>
#include <cmath>

using namespace std;

 double epsilon;
 
// Definición de la función
double funcion(double x) {
    return x * x - 5;
}

// Función para aproximar la derivada utilizando diferencias finitas hacia adelante
double aproximarDerivada(double (*funcion)(double), double x, double h) {
    return (funcion(x + h) - funcion(x)) / h;
}

int iter;

// Método de Newton-Raphson utilizando la aproximación de la derivada
double newtonRaphson(double x0, double epsilon, int maxIter) {
    double x = x0;
	iter = 0;
    while (abs(funcion(x)) > epsilon && iter < maxIter) {
        // Utilizar la aproximación de la derivada en lugar de derivada(x)
        x = x - funcion(x) / aproximarDerivada(funcion, x, epsilon);
        iter++;
    }

    return x;
}

int main() {
	
    double x0;  
	cout << "> Ingresa el valor inicial: "; cin >> x0;   // Valor inicial
	
    // Tolerancia
    cout << "> Ingresa la tolerancia: "; cin >> epsilon; 
    
    
    int maxIter;   // Número máximo de iteraciones
	cout << "> Ingresa el número máximo de iteraciones: "; cin >> maxIter; 
	
    double resultado = newtonRaphson(x0, epsilon, maxIter);

    if (abs(funcion(resultado)) < epsilon) {
        cout << "\nLa solución aproximada es: " << resultado << " dada en " << iter << " iteraciones." << endl;
    } else {
        cout << "No se alcanzó la convergencia en " << maxIter << " iteraciones." << endl;
    }

    return 0;
}
