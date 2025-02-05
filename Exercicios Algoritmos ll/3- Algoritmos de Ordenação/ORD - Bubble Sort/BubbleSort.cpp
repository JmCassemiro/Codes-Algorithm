#include <iostream>
#include <cmath>

using namespace std;

// Função Quick Sort

void bubbleSort(int vet[],int tam){
	
	int i;
	int j;
	int trab;
	bool troca = true;
	int limite;
	int cont=0;
	
	limite = tam -1;
	
	while(troca){
		   
		troca = false;
		
			for(i=0; i<limite; i++)
				if(vet[i] > vet[i+1]){
					
					
					trab = vet[i]; cout << "New trab:" << trab << endl;
					vet[i] = vet[i+1];
					vet[i+1] = trab;
					j = i;
					troca = true;
					cont++;
					
					
				}   	
		
				limite = j;
	}
	
	
		cout << "Contador:" << cont << endl;
	
}


int main()
{
	
	// Declarando Variáveis
	
		int vetor[1000];
		int n;
		
	
	// Entrada de dados
		
		cin >> n;
		
		
	// Estrutura de repetição
	
		for(int i=0; i<n; i++){
			
			cin >> vetor[i];
			
		}
			
		
	// Chamando a função
		
	bubbleSort(vetor,n);

	return 0;
}