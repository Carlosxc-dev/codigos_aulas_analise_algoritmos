#include <iostream>
#include<cstdlib>
#include <vector>
#include <queue>
using namespace std;
#define VERT 6
#define INFINIT 6
#define GRAPH_SIZE 6

int custo[GRAPH_SIZE];
int anterior[GRAPH_SIZE];
int grafo[GRAPH_SIZE][GRAPH_SIZE];

void bellman_ford(int source){

    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        custo[i] = INFINIT;
        anterior[i] = -1;
    }
    custo[source] = 0;

    for (int i = 0; i < GRAPH_SIZE; i++){
        for (int j = 0; j < GRAPH_SIZE; j++){
            for (int k = 0; k < GRAPH_SIZE; k++){
                 if ((k != j) && (grafo[j][k] != 0) && ( custo[k] > custo[j] + grafo[j][k])){
                    custo[k] = custo[j] + grafo[j][k];
                    anterior[k] = j;
                 }
            }
        }
    }
    
    
}

int main(int argc, char const *argv[])
{
    bellman_ford(1);
    return 0;
}
