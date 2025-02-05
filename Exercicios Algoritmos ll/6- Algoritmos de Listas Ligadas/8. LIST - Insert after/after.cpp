#include <iostream>
#include <list>

using namespace std;

int main()
{
	
	list<int> fila;
	
	list<int>::iterator p;
	
	list<int>::iterator r;
	
	int n;
	
	int x;
	
	int y;
	
	cin >> n;
	
	while(n != -1){
		
		fila.push_front(n);
		
		cin >> n;
		
	}
	
	cin >> x;
	
	cin >> y;
	
	for(p = fila.begin(); p != fila.end(); p++){
		
		if(x == *p){
			
			p++;
			
			fila.insert(p,y);
			
			p--;
			
			
		}
		
	}
	
	for(p = fila.begin(); p != fila.end(); p++){
		
		cout << *p << " ";
		
		
	}
	return 0;
}