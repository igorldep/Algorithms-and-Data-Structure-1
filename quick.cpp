#include<iostream>

using namespace std;

void Particao(int esq, int dir, int *v, int *i, int *j){
    *i = esq;
    *j = dir;
    int p, x; // p = pivo , x = valor
    p = v[(*i + *j) / 2];
    do{
        while(v[*i] < p){ (*i)++; }
        while(v[*j] > p){ (*j)--; }
        if(*i <= *j){
            x = v[*i];
            v[*i] = v[*j];
            v[*j] = x;

            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void Ordena(int esq, int dir, int *v){
    int i, j;
    Particao(esq, dir, v, &i, &j);
    if(esq < j){ Ordena(esq, j, v); }
    if(dir > i){ Ordena(i, dir, v); }
}

void QuickSort(int *v, int n){
    Ordena(0, n, v);
}


int main(){
    int i, n;
    srand(time(NULL));

    cout << "Tamanho do vetor: ";
    cin >> n;

    int vetor[n];

    for(i=0;i<n;i++){
        vetor[i] = rand()%1000;
        cout << vetor[i] << ' ';
    }
    cout << endl << endl;
    //Ordena
    QuickSort(vetor, n-1);

    cout << "Quicksort:" << endl;
    for(i=0; i<n;i++){
        cout << vetor[i] << ' ';
    }
    cout << endl;

    return 0;
}
