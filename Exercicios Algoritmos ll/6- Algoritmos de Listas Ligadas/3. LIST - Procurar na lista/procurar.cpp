#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x){
	
	list<int>::iterator y;
	
	bool achou = false;
	
	for(y = lista.begin(); y != lista.end(); y++){
		
		if(*y == x)
			achou = true;
	}
	
	return achou;
	
	
}


int main()
{
	
	// Declarando variaveis
	
	int num; // Numero  ser pesquisado 
	
	list<int>lista; // Variavel lista
	
	int x; // Numeros a serem adicionados na lista
	
	bool e; // Variavel para chamada da função
	
	
	
	// Adicionando elementos na lista
	
	cin >> x;
	
	while(x != 0){
		
		lista.push_back(x);
		cin >> x;
	}
	
	// Numero a ser pesquisado
	
	cin >> num; 
	
	
	// Chamando a função 
	e = encontrar(lista,num);
	
	// Saida de dados
	
	if(e == false)
		cout << "Nao Encontrado" << endl;
	
	else
		cout << "Encontrado" << endl;
	
	// Liberando memoria
	
	while(!lista.empty()){
		
		lista.pop_front();
		
	}

	return 0;
}