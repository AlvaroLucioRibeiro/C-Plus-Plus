#include <iostream>
using namespace std;

// Função que implementa a bubbleSort
void bubbleSort(int vetor[], int tamanho)
{
	int i, j; // contadores
	int trab;
	bool troca;
	int limite;
	troca = true;
	limite = tamanho - 1;
	i = 0;
	while (troca)
	{
		troca = false;
		cout << "Teste numero: " << i << endl; 
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				cout << "Trab antes: " << trab << endl;
				vetor[i] = vetor[i + 1];
				cout << "Trab durante: " << trab << endl;
				vetor[i + 1] = trab;
				cout << "Trab depois: " << trab << endl;
				j = i;
				troca = true;
			}
			cout << "Finalizou primeira vez!!!" << endl << endl;
		limite = j;
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	// Declaração de variáveis
	int tam = 0, i; // Tamanho
	int vet[100];// Vetor
	int numero; // Variavel auxiliar

	// Processamento de dados
	cin >> numero;
	while (numero != 0)
	{
		vet[tam] = numero;
		tam++;
		cin >> numero;
	}

	// Saída de dados
	bubbleSort (vet, tam);
	for (i = 0; i < tam; i++)
		cout << vet[i] << " ";
	return 0;
}