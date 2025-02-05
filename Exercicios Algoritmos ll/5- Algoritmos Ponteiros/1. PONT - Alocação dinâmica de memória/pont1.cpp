#include <iostream>
#include <iomanip>

using namespace std;


struct dado{
	
	float nota1;
	
	float nota2;
	
	float nota3;
	
	float nota4;
	
	float media;
	
}*notas = NULL;

int main()
{
	
	notas = new dado;
	
	cin >> notas->nota1;
	
	cin >> notas->nota2;
	
	cin >> notas->nota3;
	
	cin >> notas->nota4;
	
	notas->media = (notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4) / 4;
	
	cout<<fixed<<setprecision(2)<<endl;
	
	cout << notas->media << endl;
	
	delete notas;
	   	
	return 0;
}