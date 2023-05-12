#include <iostream>
using namespace std;
// Função para realizar potenciação
int potencia(int a, int n)
{
	if (n == 0)
		return 1;
	else
		return a * potencia(a, n - 1);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declaração de Variaveis
	int a; // Valor de 'a'
	int n; // Valor de 'a' elevado a 'n'
	int resultado; // Resultado
	// Entrada de Dados
	cin >> a;
	cin >> n;
	// Chamada de função
	resultado = potencia(a, n);
	// Saída de Dados
	cout << resultado;
	cout << endl;
	return 0;
}