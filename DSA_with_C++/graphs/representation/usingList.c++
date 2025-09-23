#include<iostream>
#include<list>
using namespace std;


int main()
{
    int m, n;
    cin>> n >> m;

    list<int> adj[n+1]; // n+1 for 1 based indexing

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >>v;

        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
        
    }
    for(int j=1;j<=n;j++)
        {
            cout << j << "-> ";
            for(int x: adj[j])
            {
                cout << x << " ";
            }
            cout << endl;
        }
}