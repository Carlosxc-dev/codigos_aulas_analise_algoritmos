#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

void print(int *vet, int n)
{

    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
}

void shell(int vet[], int n)
{
    int aux, j, h;
    h = n / 2;

    // repete ate o incremento ser igual a 1
    while (h >= 1)
    {
        for (int i = 1; i < n; i++)
        {
            aux = vet[i];

            // comparar e movimentar com o passo h
            for (int j = i - h; (j >= 0) && (vet[j] > aux); j = j - h)
            {
                vet[j + h] = vet[j];
            }
            vet[j + h] = aux;
        }
        // diminuir o incremeto
        h = h / 2;
    }
}

void mergeIntercala(int *vet, int *aux, int ini, int meio, int fim){
    int atual, fimEsq, n;
    atual = ini; //indice atual no vetor aux - comeca em ini
    fimEsq = meio-1;//fim da primeira metade
    n = fim - ini + 1;//tamanho do vetor

    // intercala vetores tomando do ellem em ini ou meio
    //ate que uma das metades acabe 
    while ((ini <= fimEsq)&&(meio<= fim))
    {
        if (vet[ini] <= vet[meio])
        {
            aux[atual++] = vet[ini++]; //aux[atual] recebe o valor da primeira metade
        }else{
            aux[atual++] = vet[meio++] ;//aux[atual] recebe o valor da segunda metade
        }
    }

    //completa com restante da metade que sobrou 
    while (ini <= fimEsq)
    {
        aux[atual++]  = vet[ini++];
    }
    //completa com restante da metade que sobrou
    while (meio <= fim)
    {
        aux[atual++] = vet[meio++];
    }
    //copia de aux para vet
    for (int i = 0; i < n; i++)
    {
        vet[fim] = aux[fim];
        fim--;
    }

}

void mergeDivide(int *vet, int *aux, int ini, int fim){
    int meio;

    if (fim > ini){
        meio = (fim + ini)/2;
        //divide problema em 2
        mergeDivide(vet, aux, ini, meio);       
        mergeDivide(vet, aux, meio+1, fim);
        //intercala metades
        mergeIntercala(vet , aux, ini, meio+1, fim);
    }
}

void merge(int vet[] , int n){
    int aux[n];

    mergeDivide(vet, aux, 0, n-1);
}

int main(int argc, char const *argv[])
{
    int vet[MAX]; //= {1, 5, 9, 3, 8, 7, 6, 2, 4, 10};
    int aux;

    for (int i = 0; i < MAX; i++)
    {
        vet[i] = rand() % MAX;
        cout << vet[i] << " ";
    }

    // shell(vet, MAX);
    merge(vet, MAX);
    print(vet, MAX);

    return 0;
}



