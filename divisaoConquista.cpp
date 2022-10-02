#include <iostream>
#include <cstdlib>
#define MAX 10
using namespace std;

void print(int *vet, int n)
{

    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << " ";
    }
}

int particiona(int vet[], int ini, int fim){
    int i, j , pivo, aux;
    i = ini;
    j= fim;
    pivo = vet[ini];

    while (i < j)
    {
        while ((vet[i] <= pivo ) && (i < fim))
        {
            i++;
        }
        while ((vet[j] >= pivo)&&(j > ini))
        {
            j--;
        }
        if(i < j ){//se nao se cruzam troca 
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        }
    }
    vet[ini] = vet[j];
    vet[j] = pivo;
    return j;
    

}

void quick(int vet[], int ini, int fim){
    if (ini < fim ){
        int pivo  = particiona(vet, ini, fim);
        quick(vet, ini, pivo-1);
        quick(vet, pivo+1, fim);
    }
}

bool binseach(int *vet, int chave, int ini, int fim){
    int meio = (ini + fim)/2;

    if (vet[meio] == chave )
        return true ;

    if (fim -ini <= 0)
        return false ;
    if (vet[meio] > chave )
        return binseach(vet , chave, ini , meio-1);
    else
        return binseach(vet ,chave, meio+1 , fim);
}

int main(int argc, char const *argv[])
{
    int vet[MAX] = {1, 5, 9, 2, 8, 7, 6, 2, 4, 10};
    int aux = 3;

    // for (int i = 0; i < MAX; i++)
    // {
    //     vet[i] = rand()%MAX;
    // }
    print(vet, MAX);
    // quick(vet, vet[0], vet[MAX-1]);
    cout << "\n\nvalor e == " << binseach(vet, aux ,vet[0], vet[MAX-1]);
    

    return 0;
}


