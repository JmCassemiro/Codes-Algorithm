#include <iostream>
#include <list>

using namespace std;

int main()
{
	
	list<int> pilha;
	
	int x;

	
	for(int i=0; i<4; i++){
		
		cin >> x;
		
		pilha.push_front(x);
		
	}
	

	
	while(!pilha.empty()){
		
		x = *pilha.begin();
	
		cout << x << endl;
	
		pilha.pop_front();
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}