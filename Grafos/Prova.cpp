#include <iostream>
#include <list>
#include <iomanip>
#define INT_MAX 1000
using namespace std;

struct no
{
	int v; // Vertice de destino
	float peso; // Peso da aresta
};

// Função que cria a MST_Prim
void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	list<no>::iterator p; //Iterator
	int u; // Aux contador
	int v; // Vertice
	int i = 0; // Variavel aux
	int j = 0; // Variavel aux
	int destino; // Destino
	int intree[100]; // Entrada
	int parent [100]; // Parente
	int aux_caminho[100]; // Caminho aux
	float weight; // Peso
	float dist; // Dist
	float distance[100]; // Distancia
	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;
	v = start;
	while(intree[v] == false)
	{
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
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
	}
	cout << "Caminho: ";
	i = 0;
	u = end;
	while(u != start)
	{
		aux_caminho[i] = u;
		u = parent[u];
		i++;
	}
	cout << start << " ";
	for(j = i - 1; j >= 0; j--)
		cout << aux_caminho[j] << " ";
	cout << fixed << setprecision(1) << endl;
	cout << "Tempo total: " << distance[end] << " ms" << endl;
}
// Função que cria aresta
void cria_aresta(list<no>adj[], int u, int v, float p, int orientado)
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
	int id1, id2; // ID 1 e 2
	int nNos; // Numero de nós na rede
	int orientado = 1; // Orientado
	int start; // Nó inicial
	float tempo; // Tempo em ms
	int end; // Nó final

	// Inserindo dados no grafo
	cin >> nNos >> start >> end;
	cin >> id1 >> id2 >> tempo;
	while (id1 != -1 && id2 != -1 && tempo != -1)
	{
		cria_aresta(adj, id1, id2, tempo, orientado);
		cin >> id1 >> id2 >> tempo;
	}

	// Chamando a Função Dijkstra
	dijkstra(adj, nNos, start, end);

	// Desalocando memória utilizada pela lista
	while(!adj[9].empty())
		adj[9].pop_front();
	return 0;
}
