#include <iostream>

using namespace std;

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

int main()
{
	
	// Declarando variáveis 
	
	int k;
	int m;
	
	// Entrada de dados

	cin >> k;
	cin >> m;
	
	// Repetição
	
	for(int i=0; i<m; i++){
		
		cout << hash1(k,i,m) <<" ";
		
	}
	
	
	return 0;
}