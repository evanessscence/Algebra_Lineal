#include <iostream>
#include <iomanip>
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

    cout << endl << setw(10) << "Iteración" << setw(15) << "x" << setw(15) << "f(x)" << setw(15) << "f'(x)" << setw(15) << "Error" << endl;
    
    while (abs(funcion(x)) > epsilon && iter < maxIter) {
        double derivada = aproximarDerivada(funcion, x, epsilon);
        double margenError = abs(funcion(x)) - epsilon;
        
        cout << setw(10) << iter << setw(15) << x << setw(15) << funcion(x) << setw(15) << derivada << setw(15) << margenError << endl;

        x = x - funcion(x) / derivada;
        iter++;
    }

    return x;
}
int main() {
    double x0;
    cout << "> Ingresa el valor inicial: ";
    cin >> x0; // Valor inicial

    // Tolerancia
    cout << "> Ingresa la tolerancia: ";
    cin >> epsilon;

    int maxIter; // Número máximo de iteraciones
    cout << "> Ingresa el número máximo de iteraciones: ";
    cin >> maxIter;

    double resultado = newtonRaphson(x0, epsilon, maxIter);

    if (abs(funcion(resultado)) < epsilon) {
        cout << "\nLa solución aproximada es: " << resultado << " dada en " << iter << " iteraciones." << endl;
    } else {
        cout << "No se alcanzó la convergencia en " << maxIter << " iteraciones." << endl;
    }

    return 0;
}

