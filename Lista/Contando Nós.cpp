#include <iostream>
#include <list>
using namespace std;
int contar(list<int> lista)
{
	int cont = 0; // Contador de elementos da lista
	list<int>::iterator p; // Iterador para varrer a lista

	// For para soma dos elementos
	for (p = lista.begin(); p != lista.end(); p++)
		cont++;
	return cont;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> lista; // Ponteiro para lista
	int x; // Variavel aux

	// Entrando com elementos e chamando a função
	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;
	}

	// Mostrando a soma
	cout << contar(lista) << endl;

	// Desalocando memória utilizada pela lista
	while(!lista.empty())
		lista.pop_front();
	return 0;
}