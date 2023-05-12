#include <iostream>
#include <list>
#define INT_MAX 1000
using namespace std;

struct no
{
	int v; // Vertice de destino
	int peso; // Peso da aresta
};
/*----------------------------------------------------------------------------*/
//DAG - Directed Acyclic Graph (Oriented and Acyclic)
void ordenacao_topologica(int f[], int nVertices)
{
	int i, a; //Aux var
	int greatest_element; //Aux var
	int aux_array[10]; //Aux array
	for(i = 0; i < nVertices; i++)
		aux_array[i] = f[i];
	//Finding ascending order of aux_array:
	for(i = 0; i < nVertices; i++)
		for(a = i + 1; a < nVertices; a++)
		{
			if(aux_array[i] > aux_array[a])
			{
				/*--------------------------------------------------------------
				This part finds the greatest element of array and put at the
				last position of array (n - 1).
				--------------------------------------------------------------*/
				greatest_element = aux_array[i];
				//Swaping elements(array[i] = array[a] and array[a] = array[i]):
				aux_array[i] = aux_array[a];
				aux_array[a] = greatest_element;
			}
		}
	for(i = nVertices; i >= 0 ; i--)
		for(a = 0; a < nVertices; a++)
			if(aux_array[i] == f[a])
				cout << a << " ";
	cout << endl;
}
/*----------------------------------------------------------------------------*/
//Função DFS_Visit
void DFS_VISIT(int u, int & time, int color[], int parent[], list<no>adj[], int f[])
{
    list<no>::iterator p; //Iterator
    int v;
    int d[10];
    color[u] = 1;
    time += 1;
    d[u] = time;
    for(p = adj[u].begin(); p != adj[u].end(); p++)
    {
        v = p->v; //p->v(struct v)
        if(color[v] == 0)
        {
            parent[v] = u;
            DFS_VISIT(v, time, color, parent, adj, f);
        }
    }
    color[u] = 2; // Blacken u; it is finished.
    time += 1;
    f[u] = time;
}
/*----------------------------------------------------------------------------*/
void dfs(list<no>adj[], int nVertices)
{
    int color[10]; //0 - White   1 - Gray   2 - Black
    int parent[10];
    int f[10];
    int time;
    int u;
    for(u = 0; u < nVertices; u++)
    {
        color[u] = 0;
        parent[u] = -1;
    }
    time = 0;
    for(u = 0; u < nVertices; u++)
        if(color[u] == 0)
            DFS_VISIT(u, time, color, parent, adj, f);
    ordenacao_topologica(f, nVertices);
}
/*----------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------*/
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	list<no> adj[10]; // Lista de Adjacencia
	int u, v; // Origem e Destino da aresta
	int pe = 1; // Peso da aresta
	int nVertices; // Numero de vertices do grafo
	int orientado = 0; // Orientado

	// Inserindo arestas no grafo
	cin >> nVertices >> orientado;
	cin >> u >> v;
	while (u != -1 && v != -1)
	{
		cria_aresta(adj, u, v, pe, orientado);
		cin >> u >> v;
	}

	dfs(adj, nVertices);

	// Desalocando memória utilizada pela lista
	while(!adj[8].empty())
		adj[8].pop_front();
	return 0;
}
