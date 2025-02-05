#include <iostream>

using namespace std;

int sequencial (int vetor[], int x){
	
	bool achou = false;
	int i=0;
	
	while(achou==false && i<100)
		achou = vetor[i++] == x;
	
	if (achou == true)
		return (i-1);
	
	else 
		return -1;	
	
}


int main()
{
		int v[100];
		int pos= -1;
		int x;
		int i=0;
		
		
		
		do{
			   
			   cin >> v[i];
			   
			   if(v[i] != -1)
			   	i++;
			
		}while(v[i] != -1);
		
		
		cin >> x;
		
		 
		pos= sequencial(v,x);
		
		if(pos != -1){
			
			cout<< x << " encontrado na posicao " << pos << endl;
		}
		
		else
		{
			cout<< x << " nao encontrado " << endl;
		}
		 
	return 0;
}	









