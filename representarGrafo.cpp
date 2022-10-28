#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define VERT 4

void representaMatriz(){
    int mat_adj[VERT][VERT];
    memset(mat_adj, 0, sizeof mat_adj);

    mat_adj[0][1] = 1;
    mat_adj[1][2] = 1;
    mat_adj[2][1] = 1;
    mat_adj[2][0] = 1;
    mat_adj[2][3] = 1;

    for (int i = 0; i < VERT; i++)
    {
        for (int j = 0; j < VERT; j++)
        {
            cout << mat_adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void representaLista(){
    vector<int> adj[VERT];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);

    for (int i = 0; i < VERT; i++)
    {
        cout << "lista [" << i << "]: ";
        for (auto elem: adj[i])
        {
            cout << elem << " ";
        }
        cout << "\n";
        
    }
    
}

int main(int argc, char const *argv[])
{
    
    // representaMatriz();
    representaLista();
    

    return 0;
}
