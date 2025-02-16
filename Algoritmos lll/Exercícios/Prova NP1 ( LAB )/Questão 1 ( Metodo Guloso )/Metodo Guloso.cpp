#include <iostream> 
#include <climits> 

using namespace std;

int main()
{
	int custo[8][8]; // 8 -> numero maximo de cidades
						 
	int egito = 0; // Cidade inicial 
	
	int n; // Numero de cidades
	
	cin >> n;
	
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++) 
		{
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
	
	bool vis[8]; 
	int menor_custo; 
	int custo_at; 
	int cidade_atual; 
	int proxima_cidade; 
		
	
	for(int i = 0;i < n;i++)
		vis[i] = false;
	
	// metodo guloso OBS: Pois no exercicio pedia um programa mais leve, logo, o for�a bruta � invi�vel pela quantidade 
	// memoria utilizada por causa da verifica��o de todas as possibilidades
	
	menor_custo = 0;
	cidade_atual = egito;
	for(int i = 0;i < n-1;i++) 
	{
		vis[cidade_atual] = true; // marco que ja visitei a cidade atual
		
		custo_at = INT_MAX;
		for(int j = 0;j < n;j++)
		{
			if(!vis[j] && custo_at > custo[cidade_atual][j])
			{
				proxima_cidade = j;
				custo_at = custo[cidade_atual][j];

			}	
		}
		menor_custo += custo_at;
		cidade_atual = proxima_cidade;

		cout<<cidade_atual<<endl;
	}
	
	return 0;
}
