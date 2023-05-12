#include <iostream>
#include <list>
using namespace std;

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> fila; // Ponteiro para fila
	int x; // Variavel aux para leitura
	int i; // Contador

	// Entrada de x e inserção na fila
	for (i = 0; i < 4; i++)
	{
		cin >> x;
		fila.push_back(x);
	}

	// Removendo e mostrando os elementos da fila
	// !fila.empty() = Enquanto a fila não estiver vazia
	while(!fila.empty()) 
	{
		cout << *fila.begin() << " ";
		fila.pop_front();
	}
	return 0;
}