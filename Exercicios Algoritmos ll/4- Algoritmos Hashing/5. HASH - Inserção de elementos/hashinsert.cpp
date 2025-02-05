#include <iostream>

using namespace std;


struct dado{
	
	int k; // chave a ser inserida no vetor
	int status; 
	
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
				
int main()
{
	
	int m; // tamanho da tabela
	int k; // numeros a serem inseridos
	int h;
	
	
	
	
	cin >> m;
	
	for(int i=0; i < m; i++){
		
		t[i].k = -1;
		t[i].status = 0;
	}
	
	cin >> k;
	
	
	while(k != 0){
		
		h = hash_insert(t,m,k);
		
		cin >> k;
		
		
	}
	
	
	
	
	
	for(int i=0; i < m; i++){
		
	cout << t[i].k << " ";
		
	}
	
	
	return 0;
}