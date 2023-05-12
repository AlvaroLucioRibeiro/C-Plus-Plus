#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Struct para dados
struct dados
{
	int codigo; // codigo do produto
	int quantidade; // quantidade em estoque
	float preco; // preco unitario
};

// Função que implementa a QuickSort
void quickSort(dados vetor[], int tamanho, int i, int j)
{
	int esq, dir, pivo, trabQuant, trabCod;
	float trabPreco;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)].codigo;
	do
	{
		while (vetor[esq].codigo < pivo)
			esq++;
		while (vetor[dir].codigo > pivo)
			dir--;
		if (esq <= dir)
		{
			trabQuant = vetor[esq].quantidade;
			vetor[esq].quantidade = vetor[dir].quantidade;
			vetor[dir].quantidade = trabQuant;
			trabCod = vetor[esq].codigo;
			vetor[esq].codigo = vetor[dir].codigo;
			vetor[dir].codigo = trabCod;
			trabPreco = vetor[esq].preco;
			vetor[esq].preco = vetor[dir].preco;
			vetor[dir].preco = trabPreco;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	if (dir - i >= 0)
		quickSort(vetor, tamanho, i, dir);
	if (j - esq >= 0)
		quickSort(vetor, tamanho, esq, j);
}

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração variáveis
	int n; // Numero de entradas
	int i; // Contador
	dados ordenacao [60]; // Struct

	//Entrada de dados
	cin >> n;
	while (n > 100)
	{
		cin >> n;
	}

	//Processamento de dados
	for (i = 0; i < n; i++)
	{
		cin >> ordenacao[i].codigo;
		cin >> ordenacao[i].quantidade;
		cin >> ordenacao[i].preco;
	}
	quickSort(ordenacao, n, 0, n - 1);
	// Saída de dados
	for (i = 0; i < n; i++)
	{
		cout << "Codigo: " << ordenacao[i].codigo << endl;
		cout << "Quantidade em estoque: " << ordenacao[i].quantidade << endl;
		cout << fixed << setprecision(2);
		cout << "Preco unitario: R$ " << ordenacao[i].preco << endl;
		cout << endl;
	}
	return 0;
}