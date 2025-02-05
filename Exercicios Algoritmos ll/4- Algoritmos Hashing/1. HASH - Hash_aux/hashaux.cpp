#include <iostream>

using namespace std;

int hash_aux(int k, int m){
	
	int h;
	
	h = k % m;
	
	if(h < 0)
	
		return h = h + m;	
	
	else{

		return h;
	}
}


int main()
{
	
	// Declarando variáveis 
	
	int k;
	int m;
	int f;
	
		// Entrada de dados
	
	cin >> k;
	cin >> m;
	
	 while(k != 0 && m != 0){
	
	    f = hash_aux(k,m);	
	    cout << f << endl;

		cin >> k;
		
		cin >> m;
		

	}
	
	
	
	
	
	
	return 0;
}