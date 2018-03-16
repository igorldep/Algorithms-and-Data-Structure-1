#include <iostream>
#include <random> //Gerar números aleatórios
#include <chrono> //Mede diferenças de tempo

using namespace std; //uso dos nomes de espaço: serve para evitar conflitos de nome
using namespace std::chrono; //caso não, na linha 22:   std::cin >> n;

void IniciaVetor(int v[], int n);
void ImprimeVetor(int v[], int n);

void MaxMin1(int v[], int n, int &min, int &max); //referência via referência, troca o nome da variável, mas o endereço de memória é o mesmo -> para passar vetor como referência
void MaxMin2(int v[], int n, int &min, int &max); //ponteiros guarda o endereço de memória de outra váriavel, logo, mais custoso
void MaxMin3(int v[], int n, int &min, int &max);
//Se o ultimo bit de um número binário for 1, o número é ímpar, senão, ele é par operações bit a bit é mais rápido que operações lógicas
int main()
{
	int *v = nullptr;// vetor v, nullptr: flag que indica que o vetor aponta para nada
	int n;
	int min, max;
	
	//le dimensao
	cin >> n;
	//se impar, incremeta por causa do MaxMin3
	cout << (n&1) << endl;
	if(n & 1) n++;
	
	//aloca v
	v = new int[n];
	
	IniciaVetor(v, n);
	ImprimeVetor(v, n);
	
	min = max = 0;
	MaxMin1(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	min = max = 0;
	MaxMin2(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	min = max = 0;
	MaxMin3(v, n, min, max);
	cout << min << ' ' << max << endl;
	
	//libera espaco alocado
	delete v;
	
	return 0;
}

void IniciaVetor(int v[], int n)
{	//c++.com
	//gerador de numeros aleatorios e objeto para geracao de numeros inteiros uniformes entre 0 e 1000
	mt19937 rng; //declaração do gerador
	uniform_int_distribution<int> unif_int_d(0, 1000);//inclui 1000
	int i;
	
	//tempo atual como semente para o gerador de numeros aleatorios, gerador de alta resolução, no momenyto agora, dês do moemnto de sua criação
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
 * Melhor caso, pior caso e caso medio: 2(n-1) // f(x) = 2( n - 1 )
 */
void MaxMin1(int v[], int n, int &min, int &max)
{
	int i;
	
	min = max = v[0];
	for(i = 1; i < n; i++)
	{
		if(v[i] > max) max = v[i]; //linha executada (n-1) vezes
		if(v[i] < min) min = v[i];
	}
}

/* Numero de comparacoes:
 * Melhor caso: n-1,        v ordenado crescentemente
 * Pior caso:   2(n-1),     v ordenado decrescentemente
 * Caso medio:  3(n/2)-3/2, v[i] < max em metade das vezes -> metade do melhor caso, mais, metade do pior caso
 */
void MaxMin2(int v[], int n, int &min, int &max)
{
	int i;
	//Se ele for o maior ele obviamente não será o menor. assim, já se remove algumas operações a menos
	min = max = v[0];
	for(i = 1; i < n; i++)
		if(v[i] > max)
			max = v[i];
		else if(v[i] < min) // nunca seŕa executada se o vetor estiver de forma crescente
			min = v[i];
}

/* Numero de comparacoes:
 * Melhor caso, pior caso e caso medio: 3(n/2)-2
 */
void MaxMin3(int v[], int n, int &min, int &max)
{
	int i;
	
	if(v[0] > v[1])//uma comparação
	{
		max = v[0];
		min = v[1];
	}
	else
	{
		max = v[1];
		min = v[0];
	}
	
	for(i = 2; i < n; i += 2) // tira 2: (-2)
	{
		if(v[i] > v[i+1])  //Compara de dois em dois : (n/2) ------- temos uma comparação aqui
		{
			if(v[i] > max)   max = v[i]; 
			if(v[i+1] < min) min = v[i+1];
		}//mais duas comparações, em cima ou embaixo
		else
		{
			if(v[i] < min)   min = v[i];
			if(v[i+1] > max) max = v[i+1];
		}
	}//custo do for: [(n/2)-2]
}
