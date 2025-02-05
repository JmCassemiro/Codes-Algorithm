#include <iostream>
#include <cmath>

using namespace std;

// Função Quick Sort
int cont = 0;
void quickSort(int vet[], int left, int right)
{
	if (left < right)
	{
		int pivot = vet[right];
		int i = left - 1;

		for (int j = left; j < right; j++)
		{
			if (vet[j] < pivot)
			{
				i++;
				swap(vet[i], vet[j]);
				cont++;
			}
		}
		swap(vet[i + 1], vet[right]);
		cont++;
		int pi = i + 1;

		quickSort(vet, left, pi - 1);
		quickSort(vet, pi + 1, right);
	}
}

int main()
{
	// Declarando Variáveis
	int vetor[1000];
	int n;

	// Entrada de dados
	cin >> n;

	// Estrutura de repetição
	for (int i = 0; i < n; i++)
	{
		cin >> vetor[i];
	}

	// Chamando a função
	quickSort(vetor, 0, n - 1);

	// Exibindo o vetor ordenado
	cout << "Vetor ordenado: ";
	for (int i = 0; i < n; i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl;

	// Exibindo o número de trocas
	cout << "Contador: " << cont << endl;

	return 0;
}
