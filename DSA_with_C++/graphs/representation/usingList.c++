#include<iostream>
using namespace std;


int main()
{
    int m, n;
    cin>> n >> m;

    int adj[n+1][n+1]={0}; // n+1 for 1 based indexing. Every element is initialized to 0

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >>v;

        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
        
    }
    for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                cout << adj[j][k] << " ";
            }
            cout << endl;
        }
}

// space complexity: O(n^2) for adjacency matrix
// time complexity: O(1) for adding an edge, O(n) for printing all neighbours of a node
// drawback: for a sparse graph, it takes more space
// advantage: to check if an edge exists between two nodes, it takes O(1) time