#include <iostream>
using namespace std;
// Fun��o que implementa o Hash
int hash_aux(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		return hk + m;
	else
		return hk;
}
int hash1(int k, int i, int m)
{
	int Hkim; // Resultado
	Hkim = (hash_aux(k, m) + i) % m;
	return Hkim;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declara��o vari�veis
	int k; // Chave
	int i, m; // Mod
	// Entrada de dados e Sa�da de dados
	cin >> k >> m;
	i = 0;
	hash1(k, i, m);
	for (i = 0; i < m; i++)
		cout << hash1(k, i, m) << " ";
	return 0;
}