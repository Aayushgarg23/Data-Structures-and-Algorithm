#include<bits/stdc++.h>
using namespace std;    


// time complexity: O(m*n) -> Each cell is visited at most once in the BFS traversal.
// space complexity: O(m*n) -> The queue can hold at most m*n elements in
// the worst case, and the answer matrix also takes O(m*n) space.
// approach: We can use a breadth-first search (BFS) approach to solve this problem
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n =isWater[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }

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

                if(nx>=0 && ny >=0 && nx<m && ny<n && ans[nx][ny]==-1)
                {
                    ans[nx][ny] = ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

return ans;
    }
};