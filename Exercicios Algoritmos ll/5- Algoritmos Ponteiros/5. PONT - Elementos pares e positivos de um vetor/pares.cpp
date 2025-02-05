#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	int *vetor = NULL;
	
	int n;
	
	int *p = NULL;
	
	int cont = 0;
	
	cin >> n;
	
	vetor = new int [n];
	
	p = vetor;
	
	
	
	for(int i=0; i<n; i++){
		
		cin >> *p;
		p++;
		
		
	}
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		if(*p >=0 && *p % 2 == 0 )
			cont++;
		p++;
		
	}
	 
	 cout << cont << endl;	
	
	delete [] vetor;
	
	return 0;
}