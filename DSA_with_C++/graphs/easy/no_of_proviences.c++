class Solution {
    private:
    void dfs(int v, vector<int> visited,vector<list<int>>&adj)
    {
        visited[v] =1;

        for(int i : adj[v])
        {
            if(visited[i]!=1)
            {
                dfs(i,visited,adj);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<list<int>>adj(n+1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
// ----------------visited array --------------
vector<int> visited(n+1,0); // can't use the int visited[n+1]={0}; as it gives error in leetcode bcz leetcode use clang not g++
// ----------------counting provinces --------------
int cnt=0;
for(int i=1;i<=n;i++)
{
    if(visited[i]!=1)
    {
        cnt++;
        dfs(i,visited,adj);
    }
}
return cnt;
    }
};