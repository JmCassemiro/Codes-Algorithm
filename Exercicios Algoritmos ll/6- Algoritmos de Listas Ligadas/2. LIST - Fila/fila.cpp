#include <iostream>
#include <list>

using namespace std;

int main()
{
	
	list<int> fila;
	
	int x;

	
	for(int i=0; i<4; i++){
		
		cin >> x;
		
		fila.push_back(x);
		
	}
	

	
	while(!fila.empty()){
		
		x = *fila.begin();
	
		cout << x << endl;
	
		fila.pop_front();
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}