#include <iostream>
#include<cstdlib>
#include <vector>
#include <queue>
using namespace std;
#define VERT 6
    
vector<int> adj[VERT];


void representaLista(){

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    
}


void bfs(int start)
{
    vector<int> adj[VERT];
    vector<bool> visited(VERT, false);
    queue<int> lista;
    lista.push(start);
    visited[start] = true;
    cout << start << " ";

    //enquanto a lista nao estiver vazia 
    while(!lista.empty()){
        int u = lista.front();
        lista.pop();
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if (!visited[v]){
                lista.push(v);
                visited[v] = true;
                cout << v << " ";
            }
        }        
    }
}

int main(int argc, char const *argv[])
{

    representaLista();
    bfs(1);

    return 0;
}
