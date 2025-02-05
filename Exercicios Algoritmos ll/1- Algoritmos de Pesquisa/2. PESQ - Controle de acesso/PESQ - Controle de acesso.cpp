#include <iostream>

using namespace std;


// Função de pesquisa binária 

int binaria(int v[], int id)
	{
		
		
		bool achou; // variavel aux para buscar o id
		int baixo; // aux de pesquisa
		int meio;  // aux de pesquisa
		int alto;  // aux de pesquisa
		int tamanho = 20; // tamanho maximo do vetor
		
		baixo = 0;
		alto = tamanho -1;
		achou = false;
		
		while((baixo <= alto) && (achou==false))
		{
			   
			   meio = (baixo + alto) / 2;
			   
			   if(id < v[meio])
			   		alto = meio -1;
			   	
			   	else
					   
					if( id > v[meio])
			   			baixo = meio +1;
			
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
	
	// Declaração de variaveis
	
	int vetor[20]; // tamanho do vetor
	int id; // id a ser procurada no vetor
	int i=0; // controle de posições do vetor
	int verifica; // variavel para chamar a função binaria
	

	
	// Validação de dados ate ser digitado -1
		
		do{
			
			cin >> vetor[i];
			
				
			if(vetor[i] != -1)
				i++;
		
		}while(vetor[i] != -1);
		
		// Id a ser procurada no vetor
		
			cin >> id;
		
		
		// Chamando a função binária
		
			verifica = binaria(vetor,id);
			
		
		// Saida de dados
		
			if(verifica == -1)
				
				cout<< "Nao possui acesso" <<endl;	
			
				  
			else 
				
				cout<< "Possui acesso" <<endl;
				
			
				
						
	
		
	
	
	
	
	return 0;
}