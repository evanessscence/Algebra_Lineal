#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const double epsilon = 1e-10;  // Pequeño valor para comparación con cero
// Imprimir matriz
void imprimirMatriz(double **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Encontrar y mostrar los pivotes en la matriz original
void encontrarPivotesOriginales(double **matriz, int filas, int columnas) {
	
    cout << "Pivotes en la matriz original:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != 0) {
                cout << "(" << i + 1 << ", " << j + 1 << "): " << matriz[i][j] << endl;
                break;
            }
        }
    }
    cout << endl;
}

// Encontrar y mostrar los pivotes en la matriz rref
void encontrarPivotesRREF(double **matriz, int filas, int columnas) {
    cout << "Pivotes en la matriz reducida:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] == 1) {
                cout << "( " << i + 1 << ", " << j + 1 << "): " << matriz[i][j] << endl;
                break;
            }
        }
    }
    cout << endl;
}

// Intercambiar dos filas de la matriz
void intercambiarFilas(double **matriz, int fila1, int fila2, int columnas) {
    for (int j = 0; j < columnas; ++j) {
        double temp = matriz[fila1][j];
        matriz[fila1][j] = matriz[fila2][j];
        matriz[fila2][j] = temp;
    }
}

// Hacer cero los elementos por debajo del pivote
void hacerCeroAbajo(double **matriz, int fila_pivote, int columna_pivote, int filas, int columnas) {
    for (int i = fila_pivote + 1; i < filas; ++i) {
        double factor = -matriz[i][columna_pivote] / matriz[fila_pivote][columna_pivote];
        for (int j = columna_pivote; j < columnas; ++j) {
            matriz[i][j] += factor * matriz[fila_pivote][j];
        }
    }
}

// Hacer cero los elementos por encima del pivote
void hacerCeroArriba(double **matriz, int fila_pivote, int columna_pivote, int columnas) {
    for (int i = fila_pivote - 1; i >= 0; --i) {
        double factor = -matriz[i][columna_pivote] / matriz[fila_pivote][columna_pivote];
        for (int j = columna_pivote; j < columnas; ++j) {
            matriz[i][j] += factor * matriz[fila_pivote][j];
        }
    }
}

// Llevar la matriz a su forma escalonada reducida por filas
void rref(double **matriz, int filas, int columnas) {
    int fila_actual = 0;

    for (int columna_actual = 0; columna_actual < columnas; ++columna_actual) {
        if (fila_actual >= filas) {
            break;
        }

        int fila_pivote = fila_actual;
        while (matriz[fila_pivote][columna_actual] == 0) {
            ++fila_pivote;
            if (fila_pivote == filas) {
                fila_pivote = fila_actual;
                ++columna_actual;
                if (columna_actual == columnas) {
                    break;
                }
            }
        }

        if (matriz[fila_pivote][columna_actual] != 0) {
            intercambiarFilas(matriz, fila_actual, fila_pivote, columnas);
            double pivot = matriz[fila_actual][columna_actual];
            for (int j = columna_actual; j < columnas; ++j) {
                matriz[fila_actual][j] /= pivot;
            }
            hacerCeroAbajo(matriz, fila_actual, columna_actual, filas, columnas);
            hacerCeroArriba(matriz, fila_actual, columna_actual, columnas);
            ++fila_actual;
        }
    }
}

bool validacionEntrada(int a);
int filas, columnas;
int main() {
    
    SetConsoleOutputCP(CP_UTF8);
	do {
        cout << "¿Cuántas filas desea en la matriz? > ";
        cin >> filas;
    } while (!validacionEntrada(filas));

    do {
        cout << "¿Cuántas columnas desea en la matriz? > ";
        cin >> columnas;
    } while (!validacionEntrada(columnas));

    // Crear y llenar la matriz
    double **matriz = new double *[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new double[columnas];
        for (int j = 0; j < columnas; ++j) {
            cout << "Ingrese el elemento en la posición [" << i << ", " << j << "]: ";
            cin >> matriz[i][j];
        }
    }
	system("cls");
    cout << "\n\n> MATRIZ ORIGINAL" << endl << endl;
    imprimirMatriz(matriz, filas, columnas);
    encontrarPivotesOriginales(matriz, filas, columnas);

    rref(matriz, filas, columnas);

    cout << "\n> MATRIZ ESCALONADA REDUCIDA" << endl << endl;
    imprimirMatriz(matriz, filas, columnas);
    encontrarPivotesRREF(matriz, filas, columnas);
	
	    for (int i = 0; i < filas; ++i) {
        bool allZero = true;
        bool hasSolution = true;
        for (int j = 0; j < columnas - 1; ++j) {
            if (abs(matriz[i][j]) > epsilon) {
                allZero = false;
                if (hasSolution) {
                    cout << "x" << j+1 << " = " << matriz[i][columnas - 1]/matriz[i][j];
                    hasSolution = false;
                } else {
                    cout << " = " << matriz[i][columnas - 1]/matriz[i][j] << " - " << "x" << j + 1;
                }
            }
           
        }

        // Manejo de la última columna
        if ((abs(matriz[i][columnas - 1]) > epsilon) and (allZero)) { // Si todas las entradas son 0 y la última columna es mayor a 0, entonces
        cout << "\nEl sistema es inconsistente." << endl;  // es una ariable sin solución
        exit(0);
        }
        
        if (abs(matriz[i][columnas - 1]) < epsilon) { // Si todas las entradas son 0 y la última columna es 0, entonces
            if (allZero) {
                cout << "x" << i+1 <<" es libre";  // Variable libre
            } 
            }
        
        cout << endl;
    }
    // Liberar memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0; }
    
    bool validacionEntrada(int a)
{   if (cin.fail()) {
		system("cls");
		system("COLOR 04");
        cout << "(!) Error: Ingrese un valor numérico." << endl;
        getch();
        cin.ignore();
        cin.clear();
        cin.ignore();
        return false;
    } 
    else
    {
    	return true;
    	system("COLOR F0");
	}
	

} 
