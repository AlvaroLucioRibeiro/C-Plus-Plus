#include <iostream>
using namespace std;
struct dado
{
	int k;
	int status; // 0-vazio, 1-ocupado, 2-removido
};
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

// Função que implementa o Hash_insert
int hash_insert(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{
		j = hash1(k, m, i);
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
		j = hash1(k, m, i);
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

int main()
{
	setlocale(LC_ALL, "Portuguese");
	//declaração de variáveis
	dado t[40]; // Struct
	int i; // Contador
	int m; // tamanho da tabela
	int k; // Chave
	int op; // Operador para saída
	int p; // Variavel utilizada para procura
	int r; // Variavel utilizada para remoção
	int res; // Variavel auxliar para resultado

	// Tamanho da tabela
	cin >> m;

	// Inicializa a tabela
	for (i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}

	// Caso op seja 5 finaliza o programa,
	// ao contrário entra em um caso de comando
	cin >> op;
	while (op != 5)
	{
		switch (op)
		{
			// Caso 1 utilizado para inserir
		case 1:
			cin >> k;
			hash_insert(t, m, k);
			break;

			// Caso 2 utilizado para procura e retorno
			// -1 se caso não achar ou a posição caso ache
		case 2:
			cin >> p;
			res = hash_search(t, m, p);
			if(res == -1)
				cout << -1 << endl;
			else
				cout << res << endl;
			break;

			// Caso 3 utilizado para remoção
		case 3:
			cin >> r;
			hash_remove(t, m, r);
			break;

			// Caso 4 mostrar a tabela
		case 4:
			hash_remove(t, m, r);
			cout << t[0].k;
			for (i = 1; i < m; i++)
				cout << " " << t[i].k;
			cout << endl;
			break;
		}
		cin >> op;
	}
	return 0;
}
