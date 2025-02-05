#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int pot(int a, int n)
{
	
	if(n==0)
		return 	1;
	
	else
		return a * pot(a,n-1);
	
	
}

int main()
{
	
	
	int n;
	int p; // chamada da funcao
	int a; 
	
	
	cin >> a;
	
	cin >> n;
	
	p = pot(a,n);
	
	cout << p << endl;
	
	return 0;
}