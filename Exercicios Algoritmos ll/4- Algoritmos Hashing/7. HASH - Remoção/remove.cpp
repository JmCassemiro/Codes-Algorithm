#include <iostream>

using namespace std;


struct dado{
	
	int k; // chave a ser inserida no vetor
	int status; // 1 para posião cheia, 0 para vazia, 2 para removido
	
}t[100];


int hash_aux(int k, int m){
	
	int h;
	
	h = k % m;
	
	if(h < 0)
	
		return h = h + m;	
	
	else
		
		return h;
	
}

int hash1(int k, int i, int m){
	
	int h;
	
	h = (hash_aux(k,m) + i) % m;
				
				return h;
}
				
int hash_insert(dado t[], int m, int k){
	
	int i = 0;
	int j = 0;
	
	do{
		
		j = hash1(k,i,m);
		
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
				
				return j;
		}
		
		
		else 
			i++;
		
		
	}while(i != m);
		
		return -1;
	
}

int hash_search(dado t[], int m, int k){
	
	int i=0;
	int j=0;
	
	do{
		
		j = hash1(k,i,m);
		
		if(t[j].k == k) 
			return j;
		
		i = i + 1;
		
		
		
	}while(t[j].status != 0 && i < m);
	
	return -1;
	
	
	
}

int hash_remove(dado t[], int m, int k){
	   	   
		int j=0;	  	
	
		j = hash_search(t,m,k);
	
		if(j != -1){
			
			t[j].status = 2;
			t[j].k = -1;
				return 0; // consegui remover
		

			
		}
		else
			return -1; // k nao esta na tabela	
	
}				
				
int main()
{
	
	int m; // tamanho da tabela
	int k; // numeros a serem inseridos
	int h; // variavel para chamada da função hash_insert
	int numr; // numero a ser removido
	int remove; // variavel para chamada da função hash_remove
	
	cin >> m;
	
	for(int i=0; i < m; i++){
		
		t[i].k = -1;
		t[i].status = 0;
	}
	
	cin >> k;
	
	// Inserindo numeros no vetor
	
	while(k != 0){
		
		h = hash_insert(t,m,k);
		
		cin >> k;
		
	}
	
	// Numero a ser removido	
	
		cin >> numr;
		
	// Chamando a função hash_remove
	
		remove = hash_remove(t,m,numr);
		
	
	// Saida de dados
	
	for(int i=0; i<m; i++){
		
		cout << t[i].k <<" ";
		
	}		
	
	
	return 0;
}