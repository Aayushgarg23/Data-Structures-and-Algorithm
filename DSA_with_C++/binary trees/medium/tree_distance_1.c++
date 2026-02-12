#include<bits/stdc++.h>
using namespace std;

//CSES 1132. Tree Distance I


void dfs(vector<vector<int>> &adj, int node, int parent)
{
    cout << node << " ";

    for(auto ch : adj[node])
    {
        if(ch != parent)
        {
            dfs(adj, ch, node);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++)
    {
        cout << i << "->";

        for(auto ch : adj[i])
        {
            cout << ch << " ";
            cout << endl;
        }
    }


}