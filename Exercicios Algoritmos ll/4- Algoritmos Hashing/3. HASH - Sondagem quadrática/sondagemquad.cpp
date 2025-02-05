#include <iostream>
#include <cmath>

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

int hash2(int k, int i, int m, int c1, int c2){
	
	int h;
	
	h = (hash_aux(k,m) + (c1 * i) + (c2 * (i*i) )) % m;
		return h;
	
}

int main()
{
	
	// Declarando variáveis 
	
	int k;
	int m;
	int c1;
	int c2;
	
	// Entrada de dados

	cin >> k;
	cin >> m;
	cin >> c1;
	cin >> c2;
	
	// Repetição
	
	for(int i=0; i<m; i++){
		
		cout << hash2(k,i,m,c1,c2) <<" ";
		
	}
	
	
	return 0;
}