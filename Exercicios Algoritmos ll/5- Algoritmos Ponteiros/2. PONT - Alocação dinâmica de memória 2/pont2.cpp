#include <iostream>
#include <iomanip>

using namespace std;


struct dado{
	
	int nota[4];
	
	float media;
	
}*aluno = NULL;

int main()
{
	
	int n;
	
	float mediageral = 0;
	
	float soma;
	
	cin >> n;
		
	aluno = new dado[n];
	
	for(int i=0; i<n; i++){
		
		soma = 0;
		
		for(int j=0; j<4; j++){
		
		cin >> aluno[i].nota[j];
		
		soma = soma + aluno[i].nota[j];
		
		
		
	}
		aluno[i].media = soma / 4;
		
		mediageral = mediageral + aluno[i].media;
		
	}
	
	
	mediageral = mediageral / n;
	
	cout<<fixed<<setprecision(2)<<endl;
	
	cout << mediageral << endl;
	
	delete []aluno;
	   	
	return 0;
}