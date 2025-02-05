#include <iostream>

using namespace std;

int main()
{
	
	int *vetor = NULL;
	
	int n;
	
	int *p = NULL;
	
	cin >> n;
	
	vetor = new int [n];
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		cin >> *p;
		p++;
		
		
	}
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		
		cout << *p << " ";
		p++;
		
	}
	
	delete [] vetor;
	
	return 0;
}