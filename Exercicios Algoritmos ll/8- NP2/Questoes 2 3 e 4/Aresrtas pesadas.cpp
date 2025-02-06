#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v;	  // variavel destino para struct no
	int peso; // variavel peso para struct no.
};

void cria_aresta(list<no> adj[], int u, int v, int peso, int orientado)
{
	no aux; // declaração do struct no como variavel aux.

	aux.v = v;
	aux.peso = peso;
	adj[u].push_back(aux);
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

int arestasPesadas(list<no> adj[], int s, int limiar, int nVertices)
{
	list<no>::iterator m;
	list<int> Q;
	no aux; // declaração da struct como variavel aux;
	int u;	// variavel origem
	char state[10];
	int v;		  // variavel destino;
	int cont = 0; // variavel contador para contar quantas variaveis peso são maiores que limiar.

	for (u = 0; u < nVertices; u++)
	{
		state[u] = 'u'; // nao descoberto
	}

	state[s] = 'd'; // descoberto
	Q.push_back(s);

	while (!Q.empty())
	{
		u = *Q.begin();
		Q.pop_front();

		for (m = adj[u].begin(); m != adj[u].end(); m++)
		{
			v = m->v;
			aux.peso = m->peso;

			if (state[v] == 'u')
			{
				state[v] = 'd';
				Q.push_back(v);
			}

			if (aux.peso > limiar) // if para percorrer o peso para achar variaveis com peso acima do limiar.
			{
				cont = cont + 1;
			}
		}

		state[u] = 'p'; // processado
	}

	return cont;
}

int main()
{
	list<no>::iterator q;
	list<no> adj[10];
	int u = 0; // variavel origem
	int nVertices;
	int v = 0; // variavel destino;
	int peso = 0;
	int s;			   // variavel Start;
	int orientado = 1; // declaração de grafo como orientado;
	int limiar;		   // variavel utilizada para achar peso maior do que a mesma.
	int c;			   // int que tera o valor do retorno da função aresta pesada.

	cin >> nVertices >> s; // entrada com nVertices e variavel start.

	// Lendo arestas
	while (true)
	{
		cin >> u >> v >> peso;
		if (u == -1 && v == -1 && peso == -1) // Condição de parada
			break;
		cria_aresta(adj, u, v, peso, orientado); // função cria aresta.
	}

	cin >> limiar;

	c = arestasPesadas(adj, s, limiar, nVertices);

	cout << c << " arestas com peso acima de " << limiar << endl;

	return 0;
}