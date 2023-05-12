#include <iostream>
using namespace std;
// Função para realizar fibonacci
int Comb(int n, int k)
{
	if (k == 1 || k == 0) // Condição de parada
		return n;
	else if (k == n) 
		return 1;
	else
		return Comb(n - 1, k -1) + Comb(n - 1, k);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declaração de Variaveis
	int n; // Número de pessoas
	int k; // Número de pessoas formadas
	int resultado; // Resultado
	// Entrada de Dados
	cin >> n;
	cin >> k;
	// Chamada de função
	resultado = Comb(n, k);
	// Saída de Dados
	cout << resultado;
	return 0;
}