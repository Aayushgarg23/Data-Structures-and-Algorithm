#include<bits/stdc++.h>
using namespace std;


// time complexity: O(m*n) -> Each cell is visited at most once in the BFS traversal.
// space complexity: O(m*n) -> In the worst case, the queue can hold all the cells in a row or column of the grid, which is O(m*n).
// approach: We can use a breadth-first search (BFS) approach to solve this problem. We iterate through each cell in the grid, and whenever we encounter a land cell (1), we initiate a BFS from that cell to mark all connected land cells as visited (e.g., by changing them to 0). Each time we start a new BFS, it indicates that we have found a new island, so we increment our island count. The BFS will explore all adjacent land cells (up, down, left, right) and mark them as visited until there are no more connected land cells to explore.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int ans =0;

        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    ans++;
                    grid[i][j]=0;
                }

                while(!q.empty())
                {

                    auto [x,y] = q.front();

                    for(auto d: dir)
                    {
                        int nx = x+d[0];
                        int ny = y+ d[1];

                        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                        {
                            q.push({nx,ny});
                            grid[nx][ny] =0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
