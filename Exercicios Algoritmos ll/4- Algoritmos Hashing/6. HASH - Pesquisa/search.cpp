#include <iostream>

using namespace std;


struct dado{
	
	int k; // chave a ser inserida no vetor
	int status; // 1 para posião cheia, 0 para vazia
	
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
				
int main()
{
	
	int m; // tamanho da tabela
	int k; // numeros a serem inseridos
	int h; // variavel para chamada da função hash_insert
	int search; // variavel para chamada da função hash_search
	int num; // numero a ser procurado 
	
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
	
	
	// Numero a ser procurado
	
	cin >> num; 
	
	// Chamando a função para pesquisa no vetor
	
	search = hash_search(t,m,num);
	
	// Saida de dados
	
	if(search == -1){
		
		cout << "Chave " << num << " nao encontrada " << endl;	
	}
	
	else
		 
		 cout << "Chave " << num << " encontrada na posicao " << search << endl;
	
	
	return 0;
}