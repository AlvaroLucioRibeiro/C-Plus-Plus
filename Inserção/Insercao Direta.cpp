#include <iostream>
using namespace std;
// Função que implementa a insercaoDireta
void insercaoDireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] < chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Declaração de variáveis
    int tam = 0; // Tamanho
    int i; // Contador
    int vet[100];// Vetor
    int numero; // Variavel auxiliar
    // Processamento de dados
    cin >> numero;
    while (numero != 0)
    {
        vet[tam] = numero;
        tam++;
        cin >> numero;
    }
    // Saída de dados
    insercaoDireta (vet, tam);
    for (i = 0; i < tam; i++)
        cout << vet[i] << " ";
    cout << endl;
    return 0;
}