#include <iostream>
#include <random> //bibliotecas do c++:11
#include <chrono> //tempo

using namespace std;
using namespace std::chrono;

void IniciaVetor(int v[], int n);
void ImprimeVetor(int v[], int n);

void MaxMin4(int v[], int n, int &min, int &max); //referência via referência
void MaxMinR(int v[], int left, int right, int &min, int &max);

int main()
{
	int *v = nullptr;
	int n;
	int min, max;
	
	//le dimensao
	cin >> n;
	
	//aloca v
	v = new int[n];
	
	IniciaVetor(v, n);
	ImprimeVetor(v, n);
	
	min = max = 0;
	MaxMin4(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	//libera espaco alocado
	delete[] v; //ponteiro vetor
	
	return 0;
}

void IniciaVetor(int v[], int n)
{
	//gerador de numeros aleatorios e objeto para geracao de numeros inteiros uniformes entre 0 e 1000
	mt19937 rng;
	uniform_int_distribution<int> unif_int_d(0, 1000);
	int i;
	
	//tempo atual como semente para o gerador de numeros aleatorios
	rng.seed(high_resolution_clock::now().time_since_epoch().count());
	
	for(i = 0; i < n; i++)
		v[i] = unif_int_d(rng);
}

void ImprimeVetor(int v[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
}

/* Numero de comparacoes:
 * Melhor caso, pior caso e caso medio: 3(n/2)-2
 */
void MaxMin4(int v[], int n, int &min, int &max)
{
	MaxMinR(v, 0, n-1, min, max);
}

void MaxMinR(int v[], int left, int right, int &min, int &max)
{
	int middle;
	int min1, max1, min2, max2;
	//caso base n <= 2
	if(right - left <= 1) //caso right esteja logo a direita de left -> Ocorre se a dimensão do vetor for 1 ou 2
	{
		if(v[right] > v[left]) //comparacão
		{ max = v[right]; min = v[left]; }
		else
		{ min = v[right]; max = v[left]; }
	}
	else//caso recursivo
	{
		middle = (right + left)/2;
		MaxMinR(v, left, middle, min1, max1); //função recursiva 
		MaxMinR(v, middle+1, right, min2, max2);
		
		if(min1 < min2) min = min1;
		else min = min2;
		
		if(max1 > max2) max = max1;
		else max = max2;
	}
}
/*
 *função recursiva: função capaz de chamar ela mesma com valores diferentes. 
 *Caso base: um valor onde a recursividade para e os valores começam a ser retornados.
 *Os valores retornam até chegar a primeira vez que a função foi chamada.
 *Ocorre um empilhamento de chamadas até o caso base, e ai, apresentam-se a resposta e vão voltando
 * --------------------------------------------------------------------------------------------
 *Número de operações em um algorítimo recursivo:
 *Relação de ocorrência que ocorre no algorítimo recursivo
 *Resolver a relação de recorrência para se chegar em uma relação fechada
 *
 *No casso base ocorre uma comparação
 *Caso recursivo occore quando n > 2
 *Quando n>2 não há comparação EXPLICITA do vetor, mas há a chamada de duas recursões
 *
 *comparações explicitas: T(n) = {(1, n <= 2), (2(T(n/2)), n > 2)} fórmula...asdasd 3n/2 -2
 *maxmin3 é mais eficiente e melhor que maxmin4, mesmo que possuem o mesmo valor de custo
 *pois recursão precisa de empilhar tarefas, gastando mais memória e processamento
 */