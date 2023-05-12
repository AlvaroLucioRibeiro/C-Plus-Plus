#include <iostream>
using namespace std;
struct dado
{
	int k; // chave
	int status; // 0:vazio, 1:ocupado
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
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	//declaração de variáveis
	dado t[40]; // Struct
	int i; // Contador
	int m; // tamanho
	int k; // Chave
	int res; // Variavel Aux para resultado
	int p; // Variavel utilizada para procura
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
	// Procurando a Chave desejada
	cin >> p;
	// Saída de dados
	res = hash_search(t, m, p);
	if (res == -1)
		cout << "Chave " << p << " nao encontrada" << endl;
	else
		cout << "Chave " << p << " encontrada na posicao " << res << endl;
	cout << endl;
	return 0;
}
