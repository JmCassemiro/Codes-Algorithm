#include <iostream>
#include <list>

using namespace std;
	
	
int main()
{
	
	// Declarando variaveis
	
	list<int>lista; // Variavel para estoque
	
	list<int>::iterator q; // iterator para alocar o elemento pra venda
	
	list<int>venda; // Variavel para venda
	
	int n; // Numero de opeações
	
	int y; // Numero do produto
	
	int op; // variavel para operações
	
	cin >> n;
	
	
	
	for(int i=0; i<n; i++){
		
		cin >> op;
		
		switch(op){
		
		case 1:
			
			cin >> y;
			
			lista.push_back(y);
			break;
		
		case 2:
			
			q = lista.begin();
				
    		venda.push_front(*q);
			    
			lista.pop_front(); 
			break;
	}
		
	}
	
	
	// Saida de dados
	
	cout << "Estoque: ";
	
	for( q = lista.begin(); q != lista.end(); q++){
		
		cout << *q << endl;	  		
		
	}
	
	cout << endl << "Venda: ";
	
	for( q = venda.begin(); q != venda.end(); q++){
		
		cout << *q << endl;	  		
		
	}
	

	// Liberando memoria
	
	while(!lista.empty()){
		
		lista.pop_front();
		
	}
	
	while(!venda.empty()){
		
		venda.pop_front();
		
	}

	return 0;
}