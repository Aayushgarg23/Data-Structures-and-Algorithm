#include<bits/stdc++.h>
using namespace std;


//https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7
// https://www.geeksforgeeks.org/problems/geeks-training/1/



// Memoization

// Time Complexity: O(n × 4 × 3) = O(n)
// There are n days and 4 possible values for last (0, 1, 2, 3).
// For each state, we loop through 3 possible activities.
// Space Complexity: O(n × 4) + O(n) for recursion stack

// O(n × 4) for the DP table
// O(n) for recursion call stack in the worst case

class Solution {
    private:
    
   int solve(int days, int last,vector<vector<int>>& mat,vector<vector<int>>&dp)
    {
        
        if(dp[days][last]!=-1)return dp[days][last];
        
        if(days==0)
        {
            int maxi =0;
            
            for(int i=0;i<=2;i++)
            {
                if(i!=last)
                {
                    maxi= max(maxi,mat[days][i]);
                }
            }
            
            return dp[days][last] = maxi;
        }
        
        int maxi =0;
        
        for(int i=0;i<=2;i++)
        {
            if(i!=last)
            {
                
                int curr = mat[days][i] + solve(days-1,i,mat,dp);
                
                maxi = max(maxi, curr);
            }
        }
        return dp[days][last] = maxi;
    }
    
    
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int days = mat.size();
        int last = mat[0].size();
        
        vector<vector<int>>dp(days,vector<int>(4,-1));
        
        return solve(days-1,3,mat,dp);
    }
};


// Tabulation


