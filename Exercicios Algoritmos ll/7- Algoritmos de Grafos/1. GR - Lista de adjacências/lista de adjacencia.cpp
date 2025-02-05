#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
	
	no aux; // Variavel para adicionar elementos na lista 
	
	aux.v = v;
	aux.peso = p;
	
	adj[u].push_back(aux);
	
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
		
	}
	
}


int main()
{
	
	list<no> adj[10]; // Lista de adjacencia
	
	list <no>::iterator q; // Iterator p/ mostar a lista de adjacencias
	
	int nVertices; // Numero de vertices do grafo
	
	int op; // 1: Orientado, 0; Nao orientado
	
	int o; // Vertice de origem
	
	int d; // Vertice do destino
	
	int peso; // Peso da  aresta
	
	
	
	cin >> nVertices;
	
	cin >> op;
	
	cin >> o;
	
	cin >> d;
	
	cin >> peso;
	
	while(o != -1 && d != -1 && peso != -1){
		
		cria_aresta(adj,o,d,peso,op);
		
		cin >> o;
	
		cin >> d;
	
		cin >> peso;
		
		
	}
	
	for(int i = 0; i < nVertices; i++){
		
		for(q = adj[i].begin(); q != adj[i].end(); q++){
			
			cout << i << " " << q->v << " " << q->peso << endl;
			
		}
		
		
	}
    
	
	return 0;
}