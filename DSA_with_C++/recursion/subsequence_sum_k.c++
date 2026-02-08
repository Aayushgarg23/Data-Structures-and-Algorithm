#include<bits/stdc++.h>
using namespace std;

// Given an array of integers and a target sum k, determine if there exists a 
//subsequence of the array that sums up to k. A subsequence is a sequence that
// can be derived from the array by deleting some or no elements without changing 
//the order of the remaining elements.


class Solution {
private:
    bool solve(vector<int> &arr, int k, int idx, int sum)
    {
        if (idx == arr.size()) {
            return sum == k;
        }

        // not take
        if (solve(arr, k, idx + 1, sum))
            return true;

        // take
        if (solve(arr, k, idx + 1, sum + arr[idx]))
            return true;

        return false;
    }

public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return solve(arr, k, 0, 0);
    }
};



// more efficient solution using dynamic programming approach to solve the problem in O(n*k) time complexity and O(k) space complexity

class Solution {
public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {

        vector<bool> dp(k + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int s = k; s >= num; s--) {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[k];
    }
};
