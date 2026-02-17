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


// using the dfs approach
// time complexity: O(m*n) -> Each cell is visited at most once in the DFS traversal.
// space complexity: O(m*n) -> The recursion stack can hold at most m*n elements

class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {

        // boundary + invalid checks
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;

        // mark this cell as SAFE
        board[x][y] = '#';

        // explore neighbors
        dfs(board, x+1, y);
        dfs(board, x-1, y);
        dfs(board, x, y+1);
        dfs(board, x, y-1);
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        // Step 1: run DFS from boundary 'O'
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        // Step 2: flip surrounded + restore safe
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')       // surrounded
                    board[i][j] = 'X';

                else if(board[i][j] == '#')  // safe
                    board[i][j] = 'O';
            }
        }
    }
};
