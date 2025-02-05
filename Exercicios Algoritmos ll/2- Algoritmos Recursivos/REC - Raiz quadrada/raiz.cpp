#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double raiz(double x, double y, double e)
{
	
	
	
	if(fabs((y*y) - x) <= e)
		return 	y;
	
	else
		return raiz(x,((y*y) + x) / (2 * y) , e);
	
	
}

int main()
{
	
	
	double x; // Numero para calcular a raiz
	double e; // Limitante superior para o erro
	double x0; // Estimativa inicial para raiz de x 
	double r; // Variavel para chamada da funçao
	
	
	cin >> x;
	
	cin >> x0;
	
	cin >> e;
	
	
	
	r = raiz(x,x0,e);
	
	
	cout<<fixed<<setprecision(4)<<endl;
	
	cout << r << endl;
	
	return 0;
}