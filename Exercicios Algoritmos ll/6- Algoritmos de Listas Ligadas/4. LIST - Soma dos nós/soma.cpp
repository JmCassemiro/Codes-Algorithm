#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista){
	
	int s = 0; // variavel soma
	
	list<int>::iterator y;
	
	for(y = lista.begin(); y != lista.end(); y++){
		
		s = s + *y;
		
	}
	
	return s;
	
}


int main()
{
	
	// Declarando variaveis
	
	list<int>lista; // Variavel lista
	
	int x; // Numeros a serem adicionados na lista
	
	int s; // variavel para chamada da função
	
	// Adicionando elementos na lista
	
	cin >> x;
	
	while(x != 0){
		
		lista.push_back(x);
		cin >> x;
	}
	
	// Chamando a função 
	
	s = soma(lista);
	
	// Saida de dados
	
	cout << s << endl;

	// Liberando memoria
	
	while(!lista.empty()){
		
		lista.pop_front();
		
	}

	return 0;
}