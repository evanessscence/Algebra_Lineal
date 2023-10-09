#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n, mult, digito;
	n = 7;
	for (int i=0;i<n;i++)
	{
		mult = 9*i;
		cout << "9 x " << i << ": " << mult << endl;
		int tam = trunc(log10(mult)) + 1;
		if (tam>=2)
		{
		digito = mult/10;
		digito += mult%10;
		cout << "SUMA: " << digito << endl;
		}
		
	}
}
