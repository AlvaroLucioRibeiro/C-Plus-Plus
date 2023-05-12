#include <iostream>
#include <list>
#define INT_MAX 1000
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

// Função que cria a MST_Prim
void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	list<no>::iterator p; //Iterator
	int u; // Aux contador
	int v; // Vertice
	int destino; // Destino
	int weight; // Peso
	int dist; // Dist
	int intree[100]; // Entrada
	int distance[100]; // Distancia
	int parent [100]; // Parente
	int aux_caminho[100]; // Caminho aux
	int i; // Var aux
	int j; // Var aux

	for (u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}

	distance[start] = 0;
	v = start;

	while (intree[v] == false)
	{
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] =  distance[v] + weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;
		for (u = 0; u < nVertices; u++)
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
			cout << distance << endl;
	}
	cout << "Menor caminho: ";
	cout << start << " ";
	u = end;
	i = 0;
	while(u != start)
	{
		aux_caminho[i] = u;
		u = parent[u];
		i++;
	}
	
	for(j = i - 1; j >= 0; j--)
		cout << aux_caminho[j] << " ";
	cout << endl;
	cout << "Custo: " << distance[end];
}

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<no> adj[10]; // Lista de Adjacencia
	list<no>::iterator q; // Iterador para varrer a lista
	int u, v; // Origem e Destino da aresta
	int origem; // Origem
	int pe; // Peso da aresta
	int nVertices; // Numero de vertices do grafo
	int orientado = 0; // Orientado
	int final; // Vertice de destino
	// int i; // Contador

	// Inserindo arestas no grafo
	cin >> nVertices >> orientado >> origem >> final;
	cin >> u >> v >> pe;
	while (u != -1 && v != -1 && pe != -1)
	{
		cria_aresta(adj, u, v, pe, orientado);
		cin >> u >> v >> pe;
	}

	// Chamando a Função MST_Prim
	dijkstra(adj, nVertices, origem, final);

	// Desalocando memória utilizada pela lista
	while(!adj[8].empty())
		adj[8].pop_front();
	return 0;
}
