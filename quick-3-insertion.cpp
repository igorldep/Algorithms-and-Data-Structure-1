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
    p = v[mediana]; //pivo sera a mediana dos tres valores

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

void Ordena(int *v, int esq, int dir, int tam){
    int i, j;

    if(tam <= 40){
        InsertionSort(v, esq, dir+1);
    }else{
        tam = tam / 2;
        Particao(esq, dir, v, &i, &j);
        if(esq < j){ Ordena(v, esq, j, tam); }
        if(dir > i){ Ordena(v, i, dir, tam); }
    }
}

void QuickSort(int *v, int n, int tam){
    Ordena(v, 0, n, tam);
}

int main(){
    int i, n;
    srand(time(NULL));

    cout << "Tamanho do vetor: ";
    cin >> n;

    while(n > 0){
        int vetor[n]; //inicializa vetor
        for(i=0;i<n;i++){ // Define valores aleatorios
            vetor[i] = rand()%1000; //Ate 1000
            cout << vetor[i] << ' ';
        }
        cout << endl << endl;
        //Ordena
        QuickSort(vetor,n-1, n);
        //Imprime vetor ordenado
        cout << "Quicksort com mediana de 3 combinado com Insertion Sort:" << endl;
        for(i=0; i<n;i++){
            cout << vetor[i] << ' ';
        }
        cout << endl << endl;
        //Proximo caso de teste
        cout << "Tamanho do vetor: ";
        cin >> n;
    }
    return 0;
}
