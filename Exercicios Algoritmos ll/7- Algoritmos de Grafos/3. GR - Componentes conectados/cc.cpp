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

void bfs(list<no>adj[], int nVertices, int s){
	
	int state[10];
	int pai[10];
	int u;
	int v;
	int cont = 0;
	
	list<int> Q;
	
	list <no>::iterator p;
	
	for(u = 0; u<nVertices; u++){
		
		state[u] = -1;
		
		pai[u] = -1;
	}
	
	state[s] = 0; // Descoberto
	
	pai[s] = -1;
	
	Q.push_back(s);
	
	while(!Q.empty()){
		
		u = *Q.begin();
		
		Q.pop_front();
		
		for(p = adj[u].begin(); p!=adj[u].end(); p++){
		
		v = p->v;	
			
		if(state[v] == -1){
			
			state[v] = 0; 
			pai[v] = u;
			
			Q.push_back(v);
			
			cont++;
			
		}
		
		state[u] = 2; // processado
		
	}
		
		
	}
	
	if(cont == nVertices - 1 ){
		
		cout << "Conexo" << endl;
		
	}
		
	else
		cout << "Nao conexo" << endl;
		
}

int main()
{
	
	list<no> adj[10]; // Lista de adjacencia
	
	list<no>::iterator q; // Iterator p/ mostar a lista de adjacencias
	
	int nVertices; // Numero de vertices do grafo
	
	int o; // Vertice de origem
	
	int d; // Vertice do destino
	
	int peso = 1; // Peso da  aresta

	int s; // Aresta inicial
	
	int op = 0; // Grafo nao orientado
	
	cin >> nVertices;
	
	cin >> s;
	
	cin >> o;
	
	cin >> d;
	
	while(o != -1 && d != -1){
		
		cria_aresta(adj,o,d,peso,op);
		
		cin >> o;
	
		cin >> d;	
	}

    bfs(adj,nVertices,s);
	
	
	
	return 0;
}
