#include <iostream>
using namespace std;
// Função para realizar fatoração
int fatorial(int fat)
{
	if (fat == 0) // Condição de parada
		return 1;
	else
		return fat * fatorial (fat - 1);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declaração de Variaveis
	int fat; // Valor do fatorial a descobrir
	int resultado; // Resultado
	// Entrada de Dados
	cin >> fat;
	// Chamada de função
	resultado = fatorial(fat);
	// Saída de Dados
	cout << resultado;
	return 0;
}