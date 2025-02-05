#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	int *vetor = NULL;
	
	int n;
	
	int *p = NULL;
	
	float media1 = 0;
	
	float mediageral = 0;
	
	cin >> n;
	
	vetor = new int [n];
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		cin >> *p;
		p++;
		
		
	}
	
	p = vetor;
	
	for(int i=0; i<n; i++){
		
		
		media1 = media1 + *p;
		p++;
		
	}
	  
	  mediageral = media1 / n;
	  
	  cout<<fixed<<setprecision(2);
	  
	  cout << mediageral << endl;
	
	delete [] vetor;
	
	return 0;
}