#include <iostream>
#include <list>
#include <limits>
#include <limits.h>

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

void prim(list<no>adj[], int nVertices, int start){
	
	
	int intree[10]; // false para nao percorrido, true para percorrido
	
	int distance[10]; // distancia de um vertice para o outro 
	
	int pai[10]; // -1 nao tem pai
	
	int peso; // peso da aresta
	
	int u = 0; 
	
	int v;
	
	int destino;
	
	int dist;
	
	int soma = 0;
	
	list<no> ::iterator p;
	
		
	
	for(u = 0; u<nVertices; u++){
		
		intree[u] = false;
		distance[u] = INT_MAX;
		pai[u] = -1;
		
	}
	
	distance[start] = 0;
	
	v = start;
	
	while(intree[v] == false){
		
		intree[v] = true;
		
		for(p = adj[v].begin(); p!= adj[v].end(); p++){
			
			destino = p->v;
			peso = p->peso;
			
			if(distance[destino] > peso && intree[destino] == false){
				
				distance[destino] = peso;
				pai[destino] = v; 
				
			}
			
		}
		
		v = 0;
		dist = INT_MAX;
		
		for(u = 0; u<nVertices; u++){
			
			if(intree[u] == false && dist>distance[u]){
				
				dist = distance[u];
				v = u;
				
			}
			
		}
		
	}
	
	cout << "Arvore Geradora Minima: " <<endl;	
	
	for(u = 0; u<nVertices; u++){
		
		for(p = adj[u].begin(); p != adj[u].end(); p++){
			
			if(pai[u] == p->v)
				cout << p->v <<" "<< u <<endl;
				
		}
		
		soma = soma + distance[u];
		
	}
	
	cout << "Custo: " << soma <<endl;
	
}


int main()
{
	
	list<no> adj[10]; // Lista de adjacencia
	
	list<no>::iterator q; // Iterator p/ mostar a lista de adjacencias
	
	int nVertices; // Numero de vertices do grafo
	
	int op; // 1: Orientado, 0; Nao orientado
	
	int o; // Vertice de origem
	
	int d; // Vertice do destino
	
	int peso; // Peso da  aresta
	
	int s; // Aresta inicial
	
	cin >> nVertices;
	
	cin >> op;
	
	cin >> s;
	
	cin >> o;
	
	cin >> d;
	
	cin >> peso;
	
	while(o != -1 && d != -1 && peso != -1){
		
		cria_aresta(adj,o,d,peso,op);
		
		cin >> o;
	
		cin >> d;
	
		cin >> peso;
		
	}
	
	prim(adj,nVertices,s);
    
	
	return 0;
}