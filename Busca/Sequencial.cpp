#include <iostream>
using namespace std;

// Fun��o que implementa a busca sequencial
int sequencial(int vet[], int tam, int x)
{
	bool Encontrado = false; // variavel para busca
	int i = 0; // contador
	while (Encontrado == false && i < tam)
		Encontrado = vet[i++] == x;

	// Se x for encontrado, retorna a posi��o do mesmo no vetor
	if (Encontrado)
		return i - 1;
	// Se x n�o for encontrado, retorna -1
	else
		return -1;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	// Declara��o de vari�veis
	int tam = 0; // Tamanho
	int vet[100];// Vetor
	int x; // Se esta ou n�o no vetor
	int numero; // Variavel auxiliar
	int resultado; // Resultado da fun��o

	// Processamento de dados
	cin >> numero;
	while (numero != -1)
	{
		vet[tam] = numero;
		tam++;
		cin >> numero;
	}
	cin >> x; // N�mero de busca

	// Sa�da de dados
	resultado = sequencial(vet, tam, x);
	if (resultado != -1)
		cout << x << " encontrado na posicao " << resultado << endl;
	else
		cout << x << " nao encontrado" << endl;
}
