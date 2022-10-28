#include<iostream>
#include<vector>
#define VERT 6
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> adj[VERT];
    vector<bool> visited(VERT, false);

    // DSF
    void dfs(int u){

        if(visited[u]) 
            return ;
        visited[u] = true;
        cout << u << " - ";

        //para cada elem v , conectado a u , chame dfs recursivamente 
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][j];
            dfs(v);
        }
    } 

    //dfs explore 
    // void dfs_explore(){
    //     int cc = 0;

    //     for (int i = 0; i < VERT; i++)
    //     {
    //         if(!visited) dfs(i , cc++);
    //     }
        
    // }

    
    

    return 0;
}
