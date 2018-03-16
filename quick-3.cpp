#include<iostream>

using namespace std;

void Particao(int esq, int dir, int *v, int *i, int *j){
    *i = esq;
    *j = dir;
    int p, x, meio, mediana; // p = pivo , x = valor

    //Analise da mediana de tres valores (esquerda, meio e direita)
    meio = (*i + *j) / 2;
    if(v[*i] >= v[*j] && v[*i] <= v[meio]){
        mediana = *i;
    }else if(v[meio] >= v[*i] && v[meio] <= v[*j]){
        mediana = meio;
    }else{
        mediana = *j;
    }
    p = v[mediana]; //pivo e a mediana nos tres valores

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
    QuickSort(vetor,n-1);

    cout << "Quicksort com mediana de 3:" << endl;
    for(i=0; i<n;i++){
        cout << vetor[i] << ' ';
    }
    cout << endl;

    return 0;
}
