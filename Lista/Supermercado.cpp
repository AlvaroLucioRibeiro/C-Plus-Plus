#include <iostream>
#include <list>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> estoque; // Ponteiro para lista
	list<int> venda; // Ponteiro para lista
	list<int>::iterator p; // Iterador para varrer a lista
	int n; // Variavel para entrada N
	int op; // Variavel para entrada do operador
	int i; // Contador
	int x; // Variavel aux para produto

	// Entrando com o número de operações
	cin >> n;

	// Entrando com elementos
	for (i = 0; i < n; i++)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> x;
			estoque.push_back(x);
			break;
		case 2:
			x = *estoque.begin();
			venda.push_front(x);
			estoque.remove(x);
			break;
		}
	}

	// Mostrando o resultado
	cout << "Estoque: ";
	for (p = estoque.begin(); p != estoque.end(); p++)
		cout << *p << " ";
	cout << endl;
	cout << "Venda: ";
	for (p = venda.begin(); p != venda.end(); p++)
		cout << *p << " ";

	// Desalocando memória utilizada pela lista
	while(!estoque.empty())
		estoque.pop_front();
	while(!venda.empty())
		venda.pop_front();
	return 0;
}
