#include <iostream>
using namespace std;

struct dado
{
	float nota1; // Nota 1
	float nota2; // Nota 2
	float nota3; // Nota 3
	float nota4; // Nota 4
	float media; // Media das notas
};

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	dado *notas = NULL; // Struct
	// Alocando memória
	notas = new dado;

	// Inserindo dados
	cin >> notas->nota1;
	cin >> notas->nota2;
	cin >> notas->nota3;
	cin >> notas->nota4;

	// Mostrando dados
	notas->media = (notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4) / 4;
	cout << notas->media;

	// Liberando memória
	delete notas;

	return 0;
}