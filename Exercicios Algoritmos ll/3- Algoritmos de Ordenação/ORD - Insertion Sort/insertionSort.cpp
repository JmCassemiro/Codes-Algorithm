#include <iostream>

using namespace std;

// Função de inserção direta

void insercaoDireta(int vet[], int tam){
	
	int i,j;
	int key;
	
		for(j=1; j<tam; j++){
			
			key = vet[j];
			i = j-1;
			
			while((i >= 0) && (vet[i] < key))
			{
				
				vet[i+1] = vet[i];
				i = i-1;
				
			}
			
			vet[i+1] = key;
		}
	
		
	
}


int main()
{
	
	// Declarando variaveis
		
		int vetor[1000]; 
		int i=0; // contador
	
	
	
	// Entrada de dados
	
		cin >> vetor[i];
			
		while(vetor[i] != 0){
			
			i++;
			
			cin >> vetor[i];
				
			
		}
	
	
	// Chamando a função 
		
		insercaoDireta(vetor,i);
	
	// Saida de dados
		
		for(int j=0; j<i; j++){
			
			cout << vetor[j] << " ";
			
		}
		
	
	
	
	
	return 0;
}