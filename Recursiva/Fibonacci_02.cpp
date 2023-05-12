#include <iostream>
using namespace std;
// Função para realizar fibonacci
int Comb(int n)
{
	if (n == 1 || n == 0) // Condição de parada
		return 1;
	else
		return Comb(n - 1) + Comb(n - 2);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declaração de Variaveis
	int n; // Número de pessoas
	int resultado; // Resultado
	// Entrada de Dados
	cin >> n;
	// Chamada de função
	resultado = Comb(n);
	// Saída de Dados
	cout << resultado;
	return 0;
}