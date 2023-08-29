#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

  int tam;
  int filas;
  
void multiplicarMatrizVector()
{
	cout << "> Ingrese el tamaño del vector: "; cin >> tam;
  cout << "> Ingrese el número de filas de la matriz: "; cin >> filas;
  
  float vector1[tam];
  float MatrizSuma[tam];
  float matriz[filas][tam];
  float vectorMultiplicado[filas][tam];
  
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
	
	for (int p=0;p<filas;p++)
	{
	for (int s=0;s<tam;s++)
	{
		cout << vector1[p] << " x " << matriz[s][p] << " = " << vector1[p]*matriz[s][p] << "		";
		vectorMultiplicado[p][s] = vector1[p]*matriz[s][p];
		MatrizSuma[p] += vectorMultiplicado[p][s];
	}	
	cout << "\n\n";
	}
   
   cout << "> Matriz multiplicada: " << endl;
   
   for (int d=0;d<filas;d++)
  {
  	for (int m=0; m<tam; m++)
  	{
  	cout << vectorMultiplicado[d][m] << "	";
  	
	  }
	cout << endl;
   }
   
    cout << "\n> Matriz multiplicada sumada: " << endl;
   
   for (int d=0;d<filas;d++)
  {
	cout << MatrizSuma[d] << "	";
	cout << endl;
   }

}

void sumarMatriz()
{

  cout << "> Ingrese el número de filas de la matriz: "; cin >> filas;
	cout << "> Ingrese el número de columnas de la matriz: "; cin >> tam;
  
  float MatrizSuma[filas][tam];
  float matriz[filas][tam];
  float matriz1[filas][tam];
  
   cout << "> Ingrese los valores de la matriz 1: " << endl;
  for (int b=0;b<filas;b++)
  {
    for (int c=0;c<tam;c++)
    {
    cout << "(" << b <<", "<< c << "): ";
    cin >> matriz[b][c];
    cout << endl;
	}
   }
   
    cout << "> Ingrese los valores de la matriz 2: " << endl;
  for (int b=0;b<filas;b++)
  {
    for (int c=0;c<tam;c++)
    {
    cout << "(" << b <<", "<< c << "): ";
    cin >> matriz1[b][c];
    MatrizSuma[b][c] = matriz[b][c]+matriz1[b][c];
    cout << endl;
	}
   }
	
	cout << "\n> Matriz sumada: " << endl;
   
   for (int d=0;d<filas;d++)
  {
  	for (int c=0;c<tam;c++)
    {
	cout << "  " << MatrizSuma[d][c] << "	";
	cout << endl;
   } }
}


void multiplicarVector()
{
	 int tam;
  
  cout << "> Ingrese el tamaño de los vectores: "; cin >> tam;
  
  float vector1[tam];
  float vector2[tam];
  float vectorMultiplicado[tam];
  
  cout << "\n> Ingrese los valores del primer vector: " << endl;
  
  for (int a=0;a<tam;a++)
  {
    cout << "(" << a <<", 0): ";
    cin >> vector1[a];
    cout << endl;
   }
   
   cout << "> Ingrese los valores del segundo vector: " << endl;
  for (int b=0;b<tam;b++)
  {
    cout << "(" << b <<", 0): ";
    cin >> vector2[b];
    cout << endl;
   }
   
  for (int c=0;c<tam;c++)
  {
    vectorMultiplicado[c] = vector1[c]*vector2[c];
   }
   
   cout << "> Vector multiplicado: " << endl;
   
   for (int d=0;d<tam;d++)
  {
    cout << vectorMultiplicado[d] << endl;
   }

}

int main()
{ 
  SetConsoleOutputCP(CP_UTF8);
	int op;
	cout << "< C A L C U L A D O R A  D E  M A T R I C E S >" << endl << endl;
	cout << "> 1. Multiplicar una matriz con un vector\n> 2. Sumar matrices\n> 3. Multiplicar vectores\n\n> ";
	cin >> op;
	
	switch(op)
	{
		case 1:
			system("cls");
			multiplicarMatrizVector();
			break;
		case 2:
			system("cls");
			sumarMatriz();
			break;
		case 3:
			system("cls");
			multiplicarVector();
			break;
		default:
			cout << "Opción inválida.";
			break;
	}
return 0; }

