#include <iostream>
#include <cmath>
using namespace std;
// Função que implementa o Hash
int hash_aux(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		return hk + m;
	else
		return hk;
}
// Função que implementa o Hash1
int hash1(int k, int i, int m, int c1, int c2)
{
	int Hkim; // Resultado
	Hkim = (hash_aux(k, m) + (c1 * i) + (c2 * (i * i))) % m;
	return Hkim;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração variáveis
	int k; // Chave
	int i; // Contador
	int m; // Mod
	int c1, c2; // sondagem quadratica
	// Entrada de dados
	cin >> k >> m >> c1 >> c2;
	i = 0;
	// Chamada da Função
	hash1(k, i, m, c1, c2);
	cout << hash1(k, i, m, c1, c2);;
	// Saída de dados
	for (i = 1; i < m; i++)
		cout << " "  << hash1(k, i, m, c1, c2);
	cout << endl;
	return 0;
}
