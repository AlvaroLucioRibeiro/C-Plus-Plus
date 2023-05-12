#include <iostream>
using namespace std;
struct dado
{
	int k; // chave
	int status; // 0:vazio, 1:ocupado
};
// Fun��o que implementa o Hash_aux
int hash_aux(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		return hk + m;
	else
		return hk;
}
// Fun��o que implementa o Hash1
int hash1(int k, int i, int m)
{
	int Hkim; // Resultado
	Hkim = (hash_aux(k, m) + i) % m;
	return Hkim;
}
// Fun��o que implementa o Hash_insert
int hash_insert(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{
		j = hash1(k, i, m);
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
			i = i + 1;
	}
	while (i != m);
	return -1;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declara��o vari�veis
	dado t[40]; // Struct
	int i; // Contador
	int m; // tamanho
	int k; // Chave
	// Entrada de dados e Sa�da de dados
	cin >> m;
	// Inicializa a tabela
	for (i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}
	// Adicionando dados
	cin >> k;
	while (k != 0)
	{
		hash_insert(t, m, k);
		cin >> k;
	}
	// Sa�da de dados
	cout << t[0].k;
	for (i = 1; i < m; i++)
		cout << " " << t[i].k;
	cout << endl;
	return 0;
}
