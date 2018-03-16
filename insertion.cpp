#include<iostream>

using namespace std;
//InsertionSort sem uso de sentinela
void InsertionSort(int *v, int i, int tam){
    int j, x, inicio;
    inicio = i;
    for(i=i+1; i<tam; i++){
        x = v[i];
        j = i - 1;
        while(x < v[j] && j >= inicio){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}


int main(){
  int i, n;
  srand(time(NULL));

  cout << "Tamanho do vetor: ";
  cin >> n;
  //Crio um vetor com uma posicao a mais, devido ao uso do sentinela
  int vetor[n];

  for(i=0;i<n;i++){
    vetor[i] = rand()%1000;
    cout << vetor[i] << ' ';
  }
  cout << endl << endl;
  //Ordena
  InsertionSort(vetor, 0,  n);

  cout << "Insertion Sort:" << endl;
  for(i=0; i<n;i++){
    cout << vetor[i] << ' ';
  }
  cout << endl;

  return 0;
}
