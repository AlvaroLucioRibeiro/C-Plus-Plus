#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // Vertice de destino
	int peso; // Peso da aresta
};

void bfs(list<no>adj[], int nVertices, int s)
{
	int u; //aux var
	int v;
	int state[100]; //Array of states
	int p[100]; //Array father
	list<no>::iterator it; //Iterator
	list<int> Q; //Aux list

	for(u = 0; u < nVertices; u++)
		if(u != s)
		{
			state[u] = -1; //Undiscovered
			p[u] = -1;
		}

	state[s] = 0; //Discovered
	p[s] = -1;
	Q.push_back(s);

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop_front();
		cout << u << endl;
		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			v = it->v;
			cout << u << " " << v << endl;
			if(state[v] == -1)
			{
				state[v] = 0; //Discovered
				p[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 1; //Processed
	}

	// Desalocando memória
	while(!Q.empty())
		Q.pop_front();
}

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
	list<no> adj[6]; // Lista de Adjacencia
	list<no>::iterator q; // Iterador para varrer a lista
	int u, v; // Origem e Destino da aresta
	int s; // Origem
	int pe; // Peso da aresta
	// int i; // Contador
	int nVertices; // Numero de vertices do grafo
	int orientado = 0; // Orientado

	// Inserindo arestas no grafo
	cin >> nVertices >> s;
	cin >> u >> v >> pe;
	while (u != -1 && v != -1 && pe != -1)
	{
		cria_aresta(adj, u , v , pe, orientado);
		cin >> u >> v >> pe;
	}

	/*// Mostrando a Lista
	for (i = 0; i < nVertices; i++)
		for (q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q->peso << endl;*/

	bfs(adj, nVertices , s);
	// Desalocando memória utilizada pela lista
	while(!adj[5].empty())
		adj[5].pop_front();
	return 0;
}