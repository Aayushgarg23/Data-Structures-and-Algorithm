#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(m*n) -> Each cell is visited at most once in the BFS traversal.
// Space Complexity: O(m*n) -> The queue can hold at most m*n elements in the worst case, and the board itself takes O(m*n) space.
// Approach: We can use a breadth-first search (BFS) approach to solve this problem. We start by identifying all the 'O's on the borders of the board and mark them as safe (e.g., by changing them to a temporary character like '#'). Then, we perform a BFS from these border 'O's to mark all connected 'O's as safe. Finally, we iterate through the board and flip all remaining 'O's to 'X's, while changing the temporary character back to 'O'.

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')q.push({i,0});
            if(board[i][n-1]=='O')q.push({i,n-1});
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')q.push({0,i});
            if(board[m-1][i]=='O')q.push({m-1,i});
        }

        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

        while(!q.empty())
        {
            int size= q.size();

            while(size--)
            {
                auto [x,y] = q.front();
                q.pop();
                
                if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O')
                continue;

                board[x][y] = '#';  
                
                for(auto d: dir)
                {
                    q.push({x+d[0],y+d[1]});
                } // safe 0 -> #
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='#') board[i][j] = 'O';
            }
        }
    }
};