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
	float mediaturma; // Media da turma
	int n; // Numero de alunos
	int i; // Contador

	// Entrando com a quantidade de aluno
	cin >> n;

	// Alocando memória
	notas = new dado[n];

	// Inserindo dados
	mediaturma = 0;
	for (i = 0; i < n; i++)
	{
		cin >> notas[i].nota1;
		cin >> notas[i].nota2;
		cin >> notas[i].nota3;
		cin >> notas[i].nota4;
		notas[i].media = (notas[i].nota1 + notas[i].nota2 + notas[i].nota3 + notas[i].nota4) / 4;
		mediaturma = mediaturma + notas[i].media;
	}
	mediaturma = mediaturma / n;
	
	// Mostrando dados
	cout << mediaturma;

	// Liberando memória
	delete [] notas;

	return 0;
}