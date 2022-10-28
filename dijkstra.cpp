#include <iostream>
using namespace std;
#define INFINIT 6
#define GRAPH_SIZE 6

int custo[GRAPH_SIZE];
int anterior[GRAPH_SIZE];
bool fechado[GRAPH_SIZE];
int grafo[GRAPH_SIZE];

void dijkstra(int source)
{
    int vcm = -1;
    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        custo[i] = INFINIT;
        anterior[i] = -1;
        fechado[i] = false;
    }

    custo[source] = 0;

    while (true)
    {
        vcm = -1;
        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if ((!fechado[i]) && ((vcm == -1) || (custo[i] < custo[vcm])))
                vcm = i;
        }

        if (vcm < 0)
        {
            break;
        }
        fechado[vcm] = true;

        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if ((grafo[vcm][i] != 0) && (custo[i] > custo[vcm] + grafo[vcm][i]))
            {
                custo[i] = custo[vcm] + grafo[vcm][i];
                anterior[i] = vcm;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
