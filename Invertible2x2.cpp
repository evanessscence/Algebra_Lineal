#include<iostream>

using namespace std;

int main()
{
	int matriz[2][2];
	int inversa[2][2];
	
	cout << "Ingrese los datos de la matriz" << endl;
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
		cout << "\n(" << i <<" , "<<j<<") > ";
		cin >> matriz[i][j];
		}	
	}
	
	bool invertible;
	
	if ((matriz[0][0]-matriz[1][1])-(matriz[0][1]-matriz[1][0])!=0)
	{
		invertible = true;
	}
	else
	{
		cout << "\n(!) Esta matriz no es invertible.";
		exit(0);
	}
	
	while (invertible)
	{
	inversa[0][0] = matriz[1][1];
	inversa[0][1] = matriz[0][1]*-1;
	inversa[1][0] = matriz[1][0]*-1;
	inversa[1][1] = matriz[0][0];
	invertible = false;
	}
	cout << endl << endl;
	
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
		cout << inversa[i][j] << " ";
		}
		cout << endl;	
	}
	
}
