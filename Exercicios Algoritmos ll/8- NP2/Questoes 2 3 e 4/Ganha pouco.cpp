#include <iostream>
#include <list>
using namespace std;

//funcao para contar quantos salarios abaixo do valor de referencia  
int nAbaixo(list<int> lista, int X)
{
    list<int>::iterator p;
    int i; // contador 
    
    for(p = lista.begin(); p!= lista.end(); p++)
    {
        if(*p < X)
            i++;
    }
    
    return i; // numero de valores abaixo de x
}

int main(){
    list<int> lista;
    int X; // valor de referencia para comparacao 
    int res; // resultado final
    int N; // valores de entrada 
    
    // entrando com os numeros na lista 
    cin >> N;
    while(N != 0)
    {
        lista.push_back(N);
        cin >> N;
    }
    
    // valor de referencia para comparacao dos salarios 
    cin >> X;
    
    // executando a funcao 
    res = nAbaixo(lista, X);
    
    // saida 
    cout << res << endl;
    
    // removendo elementos da lista 
	while(!lista.empty())
		lista.pop_front();
    
    return 0;
}

