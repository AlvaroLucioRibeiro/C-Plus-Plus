#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // Vertice de destino
	int peso; // Peso da aresta
};

// Função que cria aresta
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // Variavel aux para inserir aresta no grafo
	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<no> adj[10]; // Lista de Adjacencia
	list<no>::iterator q; // Iterador para varrer a lista
	int u, v; // Origem e Destino da aresta
	int pe; // Peso da aresta
	int i; // Contador
	int nVertices; // Numero de vertices do grafo
	int orientado; // Orientado

	// Inserindo arestas no grafo
	cin >> nVertices >> orientado;
	cin >> u >> v >> pe;
	while (u != -1 && v != -1 && pe != -1)
	{
		cria_aresta(adj, u , v , pe, orientado);
		cin >> u >> v >> pe;
	}

	// Mostrando a Lista
	for (i = 0; i < nVertices; i++)
		for (q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q->peso << endl;

	// Desalocando memória utilizada pela lista
	while(!adj[10].empty())
		adj[15].pop_front();
	return 0;
}