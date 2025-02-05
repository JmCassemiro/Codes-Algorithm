#include <iostream>

using namespace std;

// Função de busca binária

int binaria(int v[], int num, int y){
	
	bool achou = false; 
	int baixo;
	int meio;
	int alto;
	
	baixo = 0;
	alto = num-1;
	
	while((baixo <= alto) && (achou == false))
	{
		meio= (baixo + alto ) / 2;
			
			if(y < v[meio])
				alto = meio - 1;
			
			
		
			else
				
				if(y > v[meio])
					baixo = meio + 1;
				
				else
					achou = true;
		
		
		
	}	
		
		if(achou)
			return meio;
		
		else 
			return -1;
	
}


int main()
{
	
	// Declarando variáveis 
	
		int n; // Número de alunos
		int mat[10000]; // Vetor para armazenamento de matriculas
		int aux; // Aux para ordenação das matriculas
		int x;	// Variavel para descobrir o corredor que o aluno irá ficar
		int corredor; // Variavel para chamar a função binaria
		
	// Entrada de dados / Validação de dados
	
		do{
			
			cin >> n; 	
			
			if(n < 1 || n > 10000)
				cout<<" Numero de alunos invalido, digite novamente "<<endl;
			
		
		}while(n < 1 || n > 10000);
		
			
	// Estrutura de repetição / Ordenação das matriculas
	
		for(int i=0; i<n; i++){
			
			cin >> mat[i];
			
		}
		
		for(int i=0; i<n; i++){
				  
				  for(int j=i+1; j<n; j++){
					  
					  if(mat[i] > mat[j]){
						  
						  aux = mat[i];
						  mat[i] = mat[j];
						  mat[j] = aux;
						  
					  }
					  
				  }
			  }
	
	
	
	 // Descobrindo se o aluno está matriculado
	 
	 	   cin >> x;	  
	
	 
	 // Chamando a função binária
	
		corredor = binaria(mat,n,x);
	
	
	// Saida de dados
	
		if(corredor == -1)
			cout<<" Nao localizado "<<endl;
		
		else
			cout<<" Corredor "<< corredor <<endl;
		
			
		
	
	
	
				
	
	
	
	return 0;
}