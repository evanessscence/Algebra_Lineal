#include<iostream>
#include<conio.h>
using namespace std;

void imprimirMatriz(double **matriz, int f, int c) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void normalizarF(double *fila, int c) {
    double leadingCoefficient = fila[0];
    if (leadingCoefficient != 0) {
        for (int i = 0; i < c; ++i) {
            fila[i] /= leadingCoefficient;
        }
    }
}

void operacionesFila(double **matriz, int f, int c, int pivote, int filaObjetivo, double factorEscalador) {
    for (int i = 0; i < c; ++i) {
        matriz[filaObjetivo][i] -= factorEscalador * matriz[pivote][i];
    }
}

void reducedRowEchelonForm(double **matriz, int f, int c) {
    int entrada = 0;

    for (int r = 0; r < f; ++r) {
        if (entrada >= c) {
            return;
        }

        int i = r;
        while (matriz[i][entrada] == 0) {
            ++i;
            if (i == f) {
                i = r;
                ++entrada;
                if (entrada == c) {
                    return;
                }
            }
        }

        for (int j = 0; j < c; ++j) {
            double temp = matriz[i][j];
            matriz[i][j] = matriz[r][j];
            matriz[r][j] = temp;
        }

        normalizarF(matriz[r], c);

        for (int i = 0; i < f; ++i) {
            if (i != r) {
                operacionesFila(matriz, f, c, r, i, matriz[i][entrada]);
            }
        }

        ++entrada;
    }
}

void mostrarPivotes(double **matriz, int f, int c) {
    cout << "Pivotes en la matriz original:" << endl;
    for (int r = 0; r < f; ++r) {
        int pivotColumn = -1;
        for (int col = 0; col < c; ++col) {
            if (matriz[r][col] != 0) {
                pivotColumn = col;
                break;
            }
        }
        if (pivotColumn != -1) {
            cout << "Fila " << r + 1 << ", Columna " << pivotColumn + 1 << endl;
        }
    }

    cout << "Pivotes en la matriz reducida:" << endl;
    for (int r = 0; r < f; ++r) {
        int pivotColumn = -1;
        for (int col = 0; col < c; ++col) {
            if (matriz[r][col] != 0) {
                pivotColumn = col;
                break;
            }
        }
        if (pivotColumn != -1) {
            cout << "Fila " << r + 1 << ", Columna " << pivotColumn + 1 << endl;
        }
    }
}

bool validacionEntrada(int a);

int main() {
    int f, c;
	bool a, b;
	
	do {
        cout << "¿Cuántas filas desea en la matriz? > ";
        cin >> f;
    } while (!validacionEntrada(f));

    do {
        cout << "¿Cuántas columnas desea en la matriz? > ";
        cin >> c;
    } while (!validacionEntrada(c));
	
    double **matrizMain = new double*[f];
    for (int i = 0; i < f; ++i) {
        matrizMain[i] = new double[c];
    }

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "Ingrese el elemento en la posición [" << i << ", " << j << "]: ";
            cin >> matrizMain[i][j];
        }
    }


    system("cls");

    cout << "MATRIZ ORIGINAL" << endl << endl;
    imprimirMatriz(matrizMain, f, c);
    reducedRowEchelonForm(matrizMain, f, c);

    cout << "\nMATRIZ REDUCIDA" << endl << endl;
    imprimirMatriz(matrizMain, f, c);
    cout << endl;
	mostrarPivotes(matrizMain, f, c);
    for (int i = 0; i < f; ++i) {
        delete[] matrizMain[i];
    }
    delete[] matrizMain;

    return 0;
}

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