#include<bits/stdc++.h>
using namespace std;


// the better is the bfs approach as it uses less space than the dfs approach. 
// The dfs approach can lead to a stack overflow if the grid is large and has a large connected component of land cells, 
// while the bfs approach uses a queue which can handle larger grids without risking a stack overflow.

// time complexity: O(m*n) -> Each cell is visited at most once in the BFS traversal.
// space complexity: O(m*n) -> The queue can hold at most m*n elements in
// the worst case, and the grid itself takes O(m*n) space.
// approach: We can use a breadth-first search (BFS) approach to solve this problem. We start by counting the total number of land cells (1s) in the grid. Then, we identify all the land cells on the borders of the grid and perform a BFS from these border land cells to mark all connected land cells as visited (e.g., by changing them to 0). For each visited land cell during the BFS, we decrement our count of total land cells. Finally, the remaining count will represent the number of enclave land cells that cannot reach the border.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)ans++;
            }
        }

        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                ans--;
                grid[i][0]=0;
            }
            if(grid[i][n-1]==1)
            {
                q.push({i,n-1});
                ans--;
                grid[i][n-1]=0;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                ans--;
                grid[0][i]=0;
            }

            if(grid[m-1][i]==1)
            {
                q.push({m-1,i});
                ans--;
                grid[m-1][i]=0;
            }
        }


        int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(auto d: dir)
            {
                int nx = x+d[0];
                int ny = y+d[1];

                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1)
                {
                    ans--;
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};




// using the dfs approach
// time complexity: O(m*n) -> Each cell is visited at most once in the DFS traversal.
// space complexity: O(m*n) -> The recursion stack can hold at most m*n elements
// approach: We can use a depth-first search (DFS) approach to solve this problem. Similar to the BFS approach, we start by counting the total number of land cells (1s) in the grid. Then, we identify all the land cells on the borders of the grid and perform a DFS from these border land cells to mark all connected land cells as visited (e.g., by changing them to 0). For each visited land cell during the DFS, we decrement our count of total land cells. Finally, the remaining count will represent the number of enclave land cells that cannot reach the border.

