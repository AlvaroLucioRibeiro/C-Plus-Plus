#include <iostream>
using namespace std;

// Função que implementa a busca binaria
int binaria(int vet[], int tam, int x)
{
	bool Encontrado = false; // variavel para busca
	int baixo, meio, alto; // variaveis auxiliares
	baixo = 0;
	alto = tam - 1;
	while ((baixo <= alto) && (Encontrado == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vet[meio])
			alto = meio - 1;
		else if (x > vet[meio])
			baixo = meio + 1;
		else
			Encontrado = true;
	}
	// Se x for encontrado, retorna a posição do mesmo no vetor
	if (Encontrado)
		return meio;
	// Se x não for encontrado, retorna -1
	else
		return -1;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	// Declaração de variáveis
	int tam = 0; // Tamanho
	int vet[100];// Vetor
	int x; // Se esta ou não no vetor
	int resultado; // Resultado da função

	// Processamento de dados
	cin >> vet[tam];
	while (vet[tam] != -1)
	{
		tam++;
		cin >> vet[tam];
	}
	cin >> x; // Número de busca

	// Saída de dados
	resultado = binaria(vet, tam, x);
	if (resultado != -1)
		cout << "Possui acesso";
	else
		cout << "Nao possui acesso";
}