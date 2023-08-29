#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
  int tam;
  int filas;
  
  SetConsoleOutputCP(CP_UTF8);
  cout << "> Ingrese el tamaño del vector: "; cin >> tam;
  cout << "> Ingrese el número de filas de la matriz: "; cin >> filas;
  
  float vector1[tam];
  float vector2[tam];
  float matriz[filas][tam];
  float vectorMultiplicado[tam];
  
  cout << "\n> Ingrese los valores del vector: " << endl;
  
  for (int a=0;a<tam;a++)
  {
    cout << "(" << a <<", 0): ";
    cin >> vector1[a];
    cout << endl;
   }
   
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
	
	for (int p=0;p<filas-1;p++)
	{
	for (int s=0;s<tam-1;s++)
	{
		cout << vector1[p] << " x " << matriz[p][s] << " = " << vector1[p]*matriz[p][s] << "		";
		cout << vector1[p] << " x " << matriz[p+1][s] << " = " << vector1[p]*matriz[p+1][s] << "		" << endl;
		vectorMultiplicado[s] = vector1[p]*matriz[p][s] + vector1[p]*matriz[p+1][s];
		cout << vectorMultiplicado[p] << endl;
	}	
	cout << "\n\n";
	}
	
	for (int p=0;p<filas-1;p++)
	{
	for (int s=0;s<tam-1;s++)
	{
		cout << vector1[s+1] << " x " << matriz[p][s+1] << " = " << vector1[p+1]*matriz[p][s+1] << "		";
		cout << vector1[s+1] << " x " << matriz[p+1][s+1] << " = " << vector1[p+1]*matriz[p+1][s+1] << "		" << endl;
		vector2[s] = vector1[p+1]*matriz[p][s+1] + vector1[p+1]*matriz[p+1][s+1];
		
	}	
	cout << endl;
	}
   
   cout << endl << "> Vector sumado: " << endl;
   
   for (int d=0;d<tam;d++)
  {
    cout << vectorMultiplicado[d];
    cout << "	" << vector2[d] << endl;
   }

return 0; }
