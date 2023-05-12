#include <iostream>
using namespace std;
void soma(int x, int y, int &s)
{
	s = x + y;
}
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int a = 2; // Primeiro termo da soma
	int b = 3; // Segundo termo da soma
	int c = 0; // a + b 
	
	// Calcular a soma
	soma(a, b, c);
	
	// Mostrar a soma
	cout << "Soma: " << c << endl; 
	return 0;
}