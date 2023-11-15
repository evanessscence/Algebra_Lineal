#include <stdio.h>
#include <math.h>
#include "tinyexpr.h"
#include "tinyexpr.c"
#include <stdlib.h>

double epsilon;

// Definición de la función
double funcion(double x)
{
	/* Store variable names and pointers. */
    te_variable vars[] = {{"x", &x}};
    char expresion[100];
    FILE *fp;
    fp = fopen("funcion.txt", "r");
    fgets(expresion, 100, fp);
    fclose(fp);
    int err;
    /* Compile the expression with variables. */
    te_expr *expr = te_compile(expresion, vars, 1, &err);

    if (expr) {
        const double h1 = te_eval(expr); /* Returns 5. */
        te_free(expr);
    } else {
        printf("Parse error at %d\n", err);
    }	
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

    printf("\n%10s%15s%15s%15s%15s\n", "Iteración", "x", "f(x)", "f'(x)", "Error");

    while (fabs(funcion(x)) > epsilon && iter < maxIter) {
        double derivada = aproximarDerivada(funcion, x, epsilon);
        double margenError = fabs(funcion(x)) - epsilon;

        printf("%10d%15lf%15lf%15lf%15lf\n", iter, x, funcion(x), derivada, margenError);

        x = x - funcion(x) / derivada;
        iter++;
    }

    return x;
}

int main() {
	
    FILE *archivo = fopen("funcion.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir la función.\n");
        return 1;
    }

    printf("Ingrese la función: ");
    
    char funciona[100];
    scanf("%99[^\n]", funciona);  // Leer la función hasta encontrar un salto de línea o llegar al límite del array

    fprintf(archivo, "%s", funciona);

    fclose(archivo);
    
    double x0;
    printf("> Ingresa el valor inicial: ");
    scanf("%lf", &x0); // Valor inicial

    // Tolerancia
    printf("> Ingresa la tolerancia: ");
    scanf("%lf", &epsilon);

    int maxIter; // Número máximo de iteraciones
    printf("> Ingresa el número máximo de iteraciones: ");
    scanf("%d", &maxIter);

    double resultado = newtonRaphson(x0, epsilon, maxIter);

    if (fabs(funcion(resultado)) < epsilon) {
        printf("\nLa solución aproximada es: %lf dada en %d iteraciones.\n", resultado, iter);
    } else {
        printf("No se alcanzó la convergencia en %d iteraciones.\n", maxIter);
    }

    return 0;
}
