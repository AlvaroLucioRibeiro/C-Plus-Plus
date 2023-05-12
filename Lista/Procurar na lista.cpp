#include <iostream>
#include <list>
using namespace std;
bool encontrar(list<int> lista, int x)
{
	list<int>::iterator p; // Iterador para varrer a lista

	// For para soma dos elementos
	for (p = lista.begin(); p != lista.end(); p++)
	{
		if(x == *p)
			return true;
		else
			return false;
	}
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> lista; // Ponteiro para lista
	int x; // Variavel aux
	int p; // Variavel aux para procura
	int res; // Variavel aux para resultado

	// Entrando com elementos e chamando a função
	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;
	}
	cin >> p;
	res = encontrar(lista, p);
	// Mostrando a soma
	if (res == true)
		cout << "Encontrado";
	else
		cout << "Nao encontrado";

	// Desalocando memória utilizada pela lista
	while(!lista.empty())
		lista.pop_front();
	return 0;
}