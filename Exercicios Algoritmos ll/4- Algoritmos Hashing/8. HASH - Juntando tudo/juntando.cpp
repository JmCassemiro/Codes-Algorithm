#include <iostream>

using namespace std;

struct dado
{
	
	int k;
	int status;
	
	
}t[100];


int h1(int k, int m){
	
	int h;
	
	h = k % m;
	
	if(h < 0)
		
		return h = h + m;	
	
	else
		
		return h;
	
}

int h2(int k, int m){
	
	int h;
	
	h = 1 + (k % (m-1));
	
	if(h < 0)
		h = h + m;
	
	return h;
		
	 	
	
	
}

int dhash(int k, int m, int i){
	
	int h;
	
	h = (h1(k,m) + (i * h2(k,m)))  % m;
		
		return h;
	
}

int hash_insert(dado t[], int m, int k){
	
	int i = 0;
	int j = 0;
	
	
	
	
	do{
		
		j = dhash(k,m,i);
		
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
				
				return j;
			
			
		}
		
		else 
			i++;
		
		
	}while(i != m);
		
		return -1;
	
}

int hash_search(dado t[], int m, int k){
	
	int i=0;
	int j=0;
	
	do{
		
		j = dhash(k,m,i);
		
		if(t[j].k == k) 
			return j;
		
		i = i + 1;
		
		
		
	}while(t[j].status != 0 && i < m);
	
	return -1;
}					

int hash_remove(dado t[], int m, int k){
	   	   
		int j=0;	  	
	
		j = hash_search(t,m,k);
	
		if(j != -1){
			
			t[j].status = 2;
			t[j].k = -1;
				return 0; // consegui remover
		

			
		}
		else
			return -1; // k nao esta na tabela	
	
}

int main()
{
	
	int m;
	int k;
	int op;
	int fim = 0;
	int pos;
	
	cin >> m;
	
	for(int i = 0; i < m; i++){
           t[i].k = -1;
           t[i].status = 0;
	}
		   	   
     
           
	do{
		
		cin >> op;  
		
		switch (op){
		
		case 1:{
			
			cin >> k;
			hash_insert(t,m,k);
			break;
		}
		
		case 2:{
			
			cin >> k;
			pos = hash_search(t,m,k);
			cout << pos << endl;
			break;
			
		}	
		
		case 3:{
			
			cin >> k;
			hash_remove(t,m,k);
			break;
			
		}
		
		case 4:{
			
			for(int i=0; i<m; i++){
				
				cout << t[i].k <<" ";
				
			}
			break;
		}	
		
		case 5:{
			
			fim++;
			break;
			
		}
			
		}
	
		
		
	}while(fim == 0);	   
		   	
	
	
	return 0;
}