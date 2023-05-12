#include <iostream>
#include <list>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> lista1; // Ponteiro para lista
	list<int> lista2; // Ponteiro para lista
	list<int> lista3; // Ponteiro unindo lista
	list<int>::iterator p; // Iterador para varrer a lista
	list<int>::iterator j; // Iterador para varrer a lista
	int x, y; // Ambas variaveis aux para entrada

	// Entrando com elementos na lista 1
	cin >> x;
	while(x != 0)
	{
		lista1.push_back(x);
		cin >> x;
	}

	// Entrando com elementos na lista 2
	cin >> y;
	while(y != 0)
	{
		lista2.push_back(y);
		cin >> y;
	}

	// Unindo as listas e mostrando a lista 3
	for (p = lista1.begin(); p != lista1.end(); p++)
		for(j = lista2.begin(); j != lista2.end(); j++)
			if (*p == *j)
				lista3.push_back(*p);

	// Gerando a lista 3
	for (p = lista3.begin(); p != lista3.end(); p++)
		cout << *p << " ";
	cout << endl;

	// Desalocando memória utilizada pela lista
	while(!lista1.empty())
		lista1.pop_front();
	while(!lista2.empty())
		lista2.pop_front();
	while(!lista3.empty())
		lista3.pop_front();
	return 0;
}
