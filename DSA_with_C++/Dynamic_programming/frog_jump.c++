#include<bits/stdc++.h>
using namespace std;



//https://takeuforward.org/plus/dsa/problems/frog-jump


// Memoization 
// time complxity: O(N) -> where N is the number of stones, as we are calculating the minimum energy required to reach each stone only once. Each stone's energy is computed based on the energy of the previous two stones, leading to a linear time complexity.
// space complexity: O(N) + O(N) -> for dp array and recursion stack space

class Solution {
public:
    int solve(int idx, vector<int> heights, vector<int>&dp)
    {
        if(idx==0) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int left = solve(idx-1,heights,dp) + abs(heights[idx]-heights[idx-1]);
        int right = INT_MAX;
        if(idx>1) right = solve(idx-2,heights,dp) + abs(heights[idx]-heights[idx-2]);

        return dp[idx] = min(left,right);

    }
    int frogJump(vector<int>& heights) {

        vector<int> dp(heights.size(),-1);

        return solve(heights.size()-1,heights,dp);
    }
};


// Tabulation
// time complexity: O(N) -> where N is the number of stones, as we are
// calculating the minimum energy required to reach each stone iteratively. Each stone's energy is computed based on the energy of the previous two stones, leading to a linear time complexity.
// space complexity: O(N) -> for the dp array used to store the minimum energy required to reach each stone.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Computes minimum energy to reach last index using bottom-up DP
    int frogJump(const vector<int>& height) {
        // Handle empty input
        if (height.empty()) return 0;

        // Fetch size of the input
        int n = (int)height.size();

        // Create dp array where dp[i] = min energy to reach i
        vector<int> dp(n, INT_MAX);

        // Base case: cost to stand on first stone is zero
        dp[0] = 0;

        // Iterate over stones from index 1 to n-1
        for (int ind = 1; ind < n; ind++) {
            // Compute cost for a jump from ind-1
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);

            // Initialize jumpTwo with large value
            int jumpTwo = INT_MAX;

            // If possible, compute cost for a jump from ind-2
            if (ind > 1) {
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }

            // Take the minimum of the two options
            dp[ind] = min(jumpOne, jumpTwo);
        }

        // Return min energy to reach last stone
        return dp[n - 1];
    }
};

int main() {
    // Define the heights array
    vector<int> height{30, 10, 60, 10, 60, 50};

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJump(height) << endl; // Expected: 40
    return 0;
}



// Space Optimization
// time complexity: O(N) -> where N is the number of stones, as we are
// space complexity: O(1) -> we are using only a constant amount of space to store the minimum energy required to reach the last two stones, instead of an entire dp array.

 int frogJump(const vector<int>& height) {
        // Handle empty input
        if (height.empty()) return 0;

        // Fetch number of stones
        int n = (int)height.size();

        // Handle single stone case
        if (n == 1) return 0;

        // Initialize the cost to reach i-1 (prev) and i-2 (prev2)
        int prev = 0;
        int prev2 = 0;

        // Iterate through stones from index 1 to n-1
        for (int i = 1; i < n; i++) {
            // Initialize jumpTwo with large value
            int jumpTwo = INT_MAX;

            // Compute cost for jumping from i-1
            int jumpOne = prev + abs(height[i] - height[i - 1]);

            // If possible, compute cost for jumping from i-2
            if (i > 1) {
                jumpTwo = prev2 + abs(height[i] - height[i - 2]);
            }

            // Determine minimal cost to reach current stone
            int cur_i = min(jumpOne, jumpTwo);

            // Shift window: update prev2 and prev
            prev2 = prev;
            prev = cur_i;
        }

        // Return minimal cost to reach last stone
        return prev;
    }