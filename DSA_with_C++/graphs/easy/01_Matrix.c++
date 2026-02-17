#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty())
        {
            
            int size = q.size();

            for(int i = 0;i<size;i++)
            {
                auto [x,y] = q.front();
                q.pop();

                

                for(auto d: dir)
                {
                    int nx = x+d[0];
                    int ny = y+d[1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && ans[nx][ny]==-1)
                    {
                        ans[nx][ny] = ans[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(m*n) -> Each cell is visited at most once in the BFS traversal.
// Space Complexity: O(m*n) -> The queue can hold at most m*n elements in the worst case, and the answer matrix also takes O(m*n) space.
