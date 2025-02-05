#include <iostream>
#include <list>

using namespace std;


void maiorMenor(list<int> lista, int &menor, int &maior)
{
	list<int>::iterator p; //ponteiro pra andar na lista
	
	p = lista.begin();
	menor = *p;
	maior = *p;
	
	while (p != lista.end())
	{
		if (*p > maior)
		    maior = *p;
		if (*p < menor)
		    menor = *p;
		p++;
	}
}


int main ()
{
	list<int>fila;//declarando a fila
	
	int x;//variavel pra leitura
	int menor;
	int maior;
	
	cin >> x; //lendo x e inserindo na lista
	do
	{
		fila.push_back(x);
		cin >> x;
    }
	}while(x !=0);
	
	// Descobrindo maior e menor elementos
	maiorMenor(fila, menor, maior);
	
	// Mostrando maior e menor elemento 
	cout << "menor: " << menor << endl; 
	cout << "maior: " << maior << endl;
	
	//liberando a memoria alocada pela lista ligada
	while (!fila.empty())
		lista.pop_front();
		
	return 0;
}