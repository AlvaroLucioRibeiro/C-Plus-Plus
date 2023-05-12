#include <iostream>
using namespace std;
struct dado
{
	int k;
	int status; // 0-vazio, 1-ocupado, 2-removido
};
// Função que implementa o Hash_aux
int hash_aux(int k, int m)
{
	int hk = 0; // Resultado
	hk = k % m;
	if (hk < 0)
		hk += m;
	return hk;
}
// Função que implementa o Hash1
int hash1(int k, int i, int m)
{
	int Hkim; // Resultado
	Hkim = (hash_aux(k, m) + i) % m;
	return Hkim;
}
// Função que implementa o Hash_insert
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
// Função que implementa o Hash_search
int hash_search(dado t[], int m, int k)
{
	int i, j; // Variaveis Aux
	i = 0;
	do
	{
		j = hash1(k, i, m);
		if (t[j].k == k)
			return j;
		i = i + 1;
	}
	while (t[j].status != 0 && i < m);
	return -1;
}
// Função que implementa o Hash_remove
int hash_remove(dado t[], int m, int k)
{
	int j; // Variavel aux
	j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0; // consegui remover
	}
	else
		return -1; // k nao esta na tabela
	}
	   int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração de variáveis
	dado t[40]; // Struct
	int i; // Contador
	int m; // tamanho
	int k; // Chave
	int res; // Variavel Aux para resultado
	int r; // Variavel utilizada para remoção
	// Entrada de dados
	cin >> m;
	// Inicializa a tabela
	for (i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}
	// Adicionando dados na Tabela
	cin >> k;
	while (k != 0)
	{
		hash_insert(t, m, k);
		cin >> k;
	}
	// Removendo a Chave desejada
	cin >> r;
	// Saída de dados
	res = hash_remove(t, m, r);
	cout << t[0].k;
	for (i = 1; i < m; i++)
		cout << " " << t[i].k;
	cout << endl;
	return 0;
}