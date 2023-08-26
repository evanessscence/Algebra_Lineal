#include<iostream>

using namespace std;

int main()
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
   cout << "<";
   
   for (int d=0;d<tam;d++)
  {
    cout << vectorMultiplicado[d] << ", ";
   }
   
   cout << ">";
return 0; }
