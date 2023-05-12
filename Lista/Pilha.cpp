#include <iostream>
#include <list>
using namespace std;

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<int> pilha; // Ponteiro para pilha
	int x; // Variavel aux para leitura
	int i; // Contador

	// Entrada de x e inserção na pilha
	for (i = 0; i < 4; i++)
	{
		cin >> x;
		pilha.push_front(x);
	}

	// Removendo e mostrando os elementos da pilha
	// !pilha.empty() = Enquanto a pilha não estiver vazia
	while(!pilha.empty()) 
	{
		cout << *pilha.begin() << " ";
		pilha.pop_front();
	}
	return 0;
}