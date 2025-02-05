#include <iostream>
#include <cstring>


using namespace std;

struct dados{
	
	char nome[40];
	
	char curso[30];
	
	int mat;
	
	
}aluno[10000];


int main()
{
	
	// Declarando variáveis 
	
		int n; // Número de alunos
		char estudante[100]; // Aluno a ser procurado
		bool encontrado = false;
		int pos = -1; // Posição do aluno
		
		
		
	// Entrada de dados / Validação de dados
	
		do{
			
			cin >> n; 	
			
			if(n < 1 || n > 10000)
				cout<<" Numero de alunos invalido, digite novamente "<<endl;
			
		
		}while(n < 1 || n > 10000);
		
	
	  // Entrada de dados	
	 
	 for(int i=0; i<n; i++){
		 
		 cin.ignore();
		 
		 cin.getline(aluno[i].nome,40);
		 
		 cin.getline(aluno[i].curso,30);
		 
		 cin >> aluno[i].mat;
		 
	 }	  		
		
	 cin.ignore();	
		
	 // Descobrindo se o aluno está matriculado
	 
   	   cin.getline(estudante,100);	  
	
	 
	 // Procurando o aluno
	
	 for(int i=0; i<n; i++){
		 
		if(strcmp(aluno[i].nome, estudante) == 0){
			 
			 pos = i;
			 encontrado = true;
			 
			 
		 }
	}
	    // Saida de dados
	
		if(encontrado == true ){
			
		cout << aluno[pos].nome << endl;
        cout << aluno[pos].curso << endl;
        cout << aluno[pos].mat << endl;
		}
		
		
		else
			cout<<" Aluno nao localizado "<<endl;
		
return 0;
    
}