#include <iostream>
using namespace std;
// Função que implementa o H1
int h1(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		return hk + m;
	else
		return hk;
}
// Função que implementa o H2
int h2(int k, int m)
{
	int hk = 0; // Resultado
	hk = 1 + (k % (m - 1));
	if (hk < 0)
		return hk + m;
	else
		return hk;
}
// Função que implementa o Hash
int hash1(int k, int m, int i)
{
	int Hkim; // Resultado
	Hkim = (h1(k, m) + i * h2(k, m)) % m;
	return Hkim;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração variáveis
	int k; // Chave
	int i; // Contador
	int m; // Mod
	// Entrada de dados
	cin >> k >> m;
	i = 0;
	// Chamada da Função
	hash1(k, m, i);
	// Saída de dados
	cout << hash1(k, m, i);
	for (i = 1; i < m; i++)
		cout << " " << hash1(k, m, i);
	cout << endl;
	return 0;
}