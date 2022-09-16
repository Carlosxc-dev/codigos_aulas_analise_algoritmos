#include<iostream>
#include<cstdlib>
#define MAX 10
using namespace std;

void print(int* vet, int n){

    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
}

void bubble(int* vet, int n){

    int aux;

    //faz as varreduras do vetor
    for (int i = 0; i < n; i++)
    {
        // troca os elemntos quando necessario
        for (int j = 0; j < n-1-i; j++)
        {
            //condicao para troca elem
            if (vet[j+1] < vet[j])
            {
                aux = vet[j]; // recebe primeiro
                vet[j] = vet[j+1]; // recebe segundo
                vet[j+1] = aux;  // recebe primeiro
            }   
        }
    }
    

}

void selection(int *vet, int n){
    int menor, aux;

    for (int i = 0; i < n-1; i++)
    {
        menor = i;
        for (int j = (i+1); j < n; j++)
        {
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
        
    }
    
}

void insertion(int *vet, int n){
    int aux, j;
    for (int i = 0; i < n; i++)
    {
        aux = vet[i];
        // laco interno caminha para traz
        for ( j = i-1; (j >= 0) && (vet[j] > aux); j--)
        {
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}

int main(int argc, char const *argv[])
{
    int vet[MAX] = {1,5,9,3,8,7,6,2,4,10};
    int aux;
    print(vet, MAX);

    // for (int i = 0; i < MAX; i++)
    // {
    //     vet[i] = rand() % MAX;
    //     cout << vet[i] << " ";
    // }

    bubble(vet, MAX);
    print(vet, MAX);
    selection(vet, MAX);
    print(vet, MAX);
    insertion(vet, MAX);
    print(vet, MAX);

    


    return 0;
}
