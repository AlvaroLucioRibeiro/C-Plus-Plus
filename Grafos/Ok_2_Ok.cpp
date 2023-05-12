#include <iostream>
#include <list>
#define INT_MAX 10000000
using namespace std;

struct no
{
	int v; // Vertice de destino
	float peso; // Peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, float p, int orientado)
{
	no aux; // Variavel aux para inserir aresta no grafo
	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if(orientado == 1)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

void prim(list<no>adj[], int nvertices, int s)
{
	list<no>::iterator p; //Iterator
	int u; // Aux contador
	int v; // Vertice
	int destino; // Destino
	int intree[100]; // Entrada
	int parent [100]; // Parente
	float weight; // Peso
	float dist; // Dist
	float distance[100]; // Distancia
	float custo = 0; // Custo
	
	for(u = 0; u < nvertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[s] = 0;
	v = s;
	while(intree[v] == false)
	{
		intree[v] = true;
		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;
			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;
		for(u = 0; u < nvertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}
	for(u = 1; u < nvertices; u++)
		cout << parent[u] << " " << u << endl;
	for(u = 0; u < nvertices; u++)
		custo = distance[u] + custo;
	cout << "Custo total: " << custo << " m" << endl;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	list<no> adj[50]; // Lista de Adjacencia
	list<no>::iterator q; // Iterador para varrer a lista
	int id1, id2; // ID 1 e 2
	float cabo; // Quantidade de cabo
	int Ligacoes; // Numero de pc a ser ligado
	int inicial; // Computador inicial
	int orientado = 1; // Orientado

	// Inserindo arestas no grafo
	cin >> Ligacoes >> inicial;
	cin >> id1 >> id2 >> cabo;
	while (id1 != -1 && id2 != -1 && cabo != -1)
	{
		cria_aresta(adj, id1, id2, cabo, orientado);
		cin >> id1 >> id2 >> cabo;
	}

	// Chamando a Função MST_Prim
	cout << "Ligações:" << endl;
	prim(adj, Ligacoes, inicial);

	// Desalocando memória utilizada pela lista
	while(!adj[9].empty())
		adj[9].pop_front();
	return 0;
}