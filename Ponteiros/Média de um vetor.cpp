#include <iostream>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int *vetor; // Ponteiro para o vetor
	int n; // Tamanho desejado para o vetor
	int i; // Contador
	float media = 0; // Média para o calculo do vetor

	// Entre com o tamanho do vetor
	cout << "Entre com o tamanho do vetor: ";
	cin >> n;

	// Alocar memória para o vetor
	vetor = new int[n];

	// Preencha o vetor
	cout << "Preencha os vetores com os números desejados: ";
	for(i = 0; i < n; i++)
	{
		cin >> vetor[i];
		media = media + vetor[i];
	}
	media = media / n;

	// Saída de dados: Mostrando a média do vetor
	cout << "Esta é a média do vetor: ";
	cout << media << endl;

	// Liberar memoria alocada para o vetor
	delete [] vetor;
	return 0;
}
