#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	int *vetor = NULL;
	
	int n;
	
	int *p = NULL;
	
	long maior;
	
	cin >> n;
	
	vetor = new int [n];
	
	p = vetor;
	
	maior = -9999999;
	
	for(int i=0; i<n; i++){
		
		cin >> *p;
		p++;
		
		
	}
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		if(*p > maior)
			maior = *p;
		p++;
		
	}
	 
	 cout << maior << endl;	
	
	delete [] vetor;
	
	return 0;
}