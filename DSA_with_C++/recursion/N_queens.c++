#include<bits/stdc++.h>
using namespace std;



// User function template for C++
class Solution {
    private:
    void solve(int n, vector<vector<string>> &ans, vector<string> &board, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n-1+col-row] = 1;
                lowerDiagonal[row+col] = 1;
                solve(n, ans, board, col+1, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n-1+col-row] = 0;
                lowerDiagonal[row+col] = 0;
            }
        }
    }
  public:
    vector<vector<string>> solveNQueens(int n) {
        // code here
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++)
        {
            board[i] = s;
        }
        
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        solve(n, ans, board, 0, leftRow, upperDiagonal, lowerDiagonal);
        
        return ans;
    }
};