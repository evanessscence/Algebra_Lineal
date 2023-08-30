#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

int filas, tam;

void transpuestaMatriz()
{
	cout << "> Ingrese el número de filas de la matriz: "; cin >> filas;
	cout << "> Ingrese el número de columnas de la matriz: "; cin >> tam;
	float matriz[filas][tam];
	cout << "> Ingrese los valores de la matriz: " << endl;
  for (int b=0;b<filas;b++)
  {
    for (int c=0;c<tam;c++)
    {
    cout << "(" << b <<", "<< c << "): ";
    cin >> matriz[b][c];
    cout << endl;
	}
   }
	
	cout << "> MATRIZ INGRESADA" << endl;
	for (int p=0;p<filas;p++)
	{
	for (int s=0;s<tam;s++)
	{
		cout <<matriz[p][s]<<"	";
	}
	cout << "\n\n";
	}
	  
   cout << "> MATRIZ TRANSPUESA: " << endl;
   
   for (int d=0;d<filas;d++)
  {
  	for (int m=0; m<tam; m++)
  	{
  	cout << matriz[m][d] << "	";
  	
	  }
	cout << endl;
   }
}

int main()
{
	transpuestaMatriz();
	return 0;
}
