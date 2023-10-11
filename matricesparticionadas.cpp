#include<iostream>

using namespace std;

int main()
{
	int fila1, fila2, col1, col2, particion1, particion2;
	
	cout << "Ingrese el tamaño de la primera matriz\n> FILAS: "; cin >> fila1;
	cout << "\n> COLUMNAS: "; cin >> col1;
	cout << "\n> PARTICIONES: "; cin >> particion1;
	double matriz1[fila1][col1];

	cout << "\n\nIngrese el tamaño de la segunda matriz\n> FILAS: "; cin >> fila2;
	cout << "> COLUMNAS: "; cin >> col2;
	cout << "\n> PARTICIONES: "; cin >> particion2;
	double matriz2[fila2][col2];
	
	if ((particion1!=particion2))
	{
		cout << "\n(!) Esta matriz no se puede sumar ya que las particiones de A y B no son exactamente del mismo tamaño.";
		
		if(col1==fila2)
		{
			cout << "\nSin embargo, se puede multiplicar.";
		}
		
		exit(0);
	}
	
	cout << "INGRESE LOS DATOS DE LA MATRIZ 1: \n";
		
		for (int i=0; i<fila2; i++)
	{
		for (int j=0; j<col2; j++)
		{
			cin >> matriz1[i][j]; 
			cout << "	";
		}
		cout << endl;
	}
	
	cout << "INGRESE LOS DATOS DE LA MATRIZ 2: \n";
		
		for (int i=0; i<fila2; i++)
	{
		for (int j=0; j<col2; j++)
		{
			cin >> matriz2[i][j]; 
			cout << "	";
		}
		cout << endl;
	}

}
