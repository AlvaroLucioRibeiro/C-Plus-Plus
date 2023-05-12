#include <iostream>
using namespace std;
// Função que implementa o Hash
int hash_aux(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		hk += m;
	return hk;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração variáveis
	int k; // Chave
	int m; // Mod
	// Entrada de dados e Saída de dados
	cin >> k >> m;
	while (k != 0 && m != 0)
	{
		cout << hash_aux(k, m) << endl;
		cin >> k >> m;
	}
	cout << endl;
	return 0;
}
