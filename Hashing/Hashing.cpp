#include <iostream>
using namespace std;
// Fun��o que implementa o Hash
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
	//declara��o vari�veis
	int k; // Chave
	int m; // Mod
	// Entrada de dados e Sa�da de dados
	cin >> k >> m;
	while (k != 0 && m != 0)
	{
		cout << hash_aux(k, m) << endl;
		cin >> k >> m;
	}
	cout << endl;
	return 0;
}
