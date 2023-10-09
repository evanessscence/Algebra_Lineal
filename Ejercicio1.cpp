#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int dos, n, digito;
	n = 7;
	dos = 2;
	for (int i=0;i<n;i++)
	{
		dos = pow(2,i);
		cout << "2^" << i << ": " << dos << endl;
		int tam = trunc(log10(dos)) + 1;
		if (tam>=2)
		{
		digito = dos/10;
		digito += dos%10;
		cout << "SUMA: " << digito << endl;
		}
		
	}
}
