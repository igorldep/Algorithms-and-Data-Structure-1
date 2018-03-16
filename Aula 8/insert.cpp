#include <iostream>

using namespace std;

void insertion (int *v, int n);
void imprime (int *v, int n);

int main (){
	int n;

	cin >> n;

	int v[n];

	for ( int i = 0; i < n; i++ )
		cin >> v[i];

	insertion (v, n);
	imprime (v, n);
}

void insertion (int *v, int n){
	int aux, i, j;
	for(i = 1; i < n; i++){
		aux = v[i];
		v[i] = 0; //valor considerado nulo
		for (j = i - 1 ; j >= 0 ; j--){
			if ( aux < v[j] )
				v[j + 1] = v[j];
			else 
				break;
		}
		v [j + 1] = aux;
	}
}

void imprime (int *v, int n){
	for (int i = 0; i < n; i++)
		cout << v[i] << " "; 

	cout << endl;
}