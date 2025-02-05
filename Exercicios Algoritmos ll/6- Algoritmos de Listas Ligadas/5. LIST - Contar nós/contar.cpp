#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista){
	
	int cont = 0; // variavel contador
	
	
	list<int>::iterator y;
	
	for(y = lista.begin(); y != lista.end(); y++){
		
		cont++;
		
	}
	
	return cont;
	
}


int main()
{
	
	// Declarando variaveis
	
	list<int>lista; // Variavel lista
	
	int x; // Numeros a serem adicionados na lista
	
	int c; // variavel para chamada da função
	
	// Adicionando elementos na lista
	
	cin >> x;
	
	while(x != 0){
		
		lista.push_back(x);
		cin >> x;
	}
	
	// Chamando a função 
	
	c = contar(lista);
	
	// Saida de dados
	
	cout << c << endl;

	// Liberando memoria
	
	while(!lista.empty()){
		
		lista.pop_front();
		
	}

	return 0;
}