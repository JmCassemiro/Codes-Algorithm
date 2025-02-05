#include <iostream>
#include <cmath>

using namespace std;

int h1(int k, int m){
	
	int h;
	
	h = k % m;
	
	if(h < 0)
		
		return h = h + m;	
	
	else
		
		return h;
	
}

int h2(int k, int m){
	
	int h;
	
	h = 1 + (k % (m-1));
	
	if(h < 0)
		h = h + m;
	
	return h;
		
	 	
	
	
}

int dhash(int k, int m, int i){
	
	int h;
	
	h = (h1(k,m) + (i * h2(k,m)))  % m;
		
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
		
		cout << dhash(k,m,i) <<" ";
		
	}
	
	
	return 0;
}