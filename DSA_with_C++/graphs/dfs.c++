#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfs(int src){
        vector<bool> visited(V, false);
        dfsUtil(src, visited);
    }
    void dfsUtil(int node, vector<bool> &visited){
        visited[node] = true;
        cout << node << " ";
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                dfsUtil(nbr, visited);
            }
        }
    }
};
int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 6);
    g.dfs(0);
    return 0;
}
