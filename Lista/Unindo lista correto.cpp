#include <iostream>
#include <list>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int vetor_aux[100]; // Vetor auxiliar
	list<int> lista; // Ponteiro para lista
	list<int>::iterator p; // Iterador para varrer a lista
	int x; // Variavel aux para entrada
	int i = 0; //Aux
	int n = 0; //Aux
	int a = 0; //Aux
	int maior; // Variavel aux para maior elemento

	// Entrando com elementos na lista 1
	cin >> x;
	while(x != 0)
	{
		i++;
		lista.push_back(x);
		cin >> x;
	}

	// Entrando com elementos na lista 2
	cin >> x;
	while(x != 0)
	{
		i++;
		lista.push_back(x);
		cin >> x;
	}

	// Usando um vetor auxiliar
	i = 0;
	for(p = lista.begin(); p != lista.end(); p++)
		vetor_aux[i++] = *p;

	// Colocando em ordem crescente
	n = i;
	for(i = 0; i < n; i++)
		for(a = i + 1; a < n; a++)
			if(vetor_aux[i] > vetor_aux[a])
			{
				maior = vetor_aux[i];
				vetor_aux[i] = vetor_aux[a];
				vetor_aux[a] = maior;
			}

	// Passando os valores iguais para 0:
	for(i = 0; i < n; i++)
		for(a = i + 1; a < n; a++)
			if(vetor_aux[i] == vetor_aux[a] && vetor_aux[i] != 0)
				vetor_aux[a] = 0;

	// Gerando a lista 3
	while(!lista.empty()) //While lista != null
		lista.pop_front();
	// Saída de dados 
	for(i = 0; i < n; i++)
		if(vetor_aux[i] != 0)
			lista.push_back(vetor_aux[i]);
	for(p = lista.begin(); p != lista.end(); p++)
		cout << *p << " ";
	cout << endl;

	// Desalocando memória utilizada pela lista
	while(!lista.empty())
		lista.pop_front();
	return 0;
}