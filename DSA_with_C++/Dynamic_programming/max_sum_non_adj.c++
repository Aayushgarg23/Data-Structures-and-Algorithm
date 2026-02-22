#include <bits/stdc++.h>
using namespace std;





// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-1/


// Memoization


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int solve(vector<int>& arr, int i, vector<int>& dp) {
        // If index is negative, no element to pick
        if (i < 0) return 0;

        // If at first element, return its value
        if (i == 0) return arr[0];

        // Return already computed value
        if (dp[i] != -1) return dp[i];

        // Include current and move 2 back
        int pick = arr[i] + solve(arr, i - 2, dp);

        // Exclude current and move 1 back
        int notPick = solve(arr, i - 1, dp);

        // Store and return max of both choices
        return dp[i] = max(pick, notPick);
    }

    // Main function to be called externally
    int maximumNonAdjacentSum(vector<int>& arr) {
        int n = arr.size();

        // DP array initialized with -1
        vector<int> dp(n, -1);

        // Start solving from last index
        return solve(arr, n - 1, dp);
    }
};

int main() {
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;

    // Output the result
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}


//tabulation
// time complexity: O(N) -> where N is the number of elements in the input array, as we are iterating through the array once to fill the dp array.
// space complexity: O(N) -> for the dp array used to store the maximum sum of non-adjacent elements up to each index.

class Solution {
public:
    // Function to return maximum sum of non-adjacent elements
    int maximumNonAdjacentSum(vector<int>& arr) {
        // Get the size of array
        int n = arr.size();

        // If array has only one element, return it
        if (n == 1) return arr[0];

        // Initialize dp array of size n
        vector<int> dp(n);

        // Base case: only one element
        dp[0] = arr[0];

        // Base case: max of first or second element
        dp[1] = max(arr[0], arr[1]);

        // Iterate from 3rd element onwards
        for (int i = 2; i < n; i++) {
            // Either take current and add dp[i-2]
            // Or skip current and take dp[i-1]
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        // Final result at last index
        for(auto x: dp) cout << x << " ";
        cout << endl;
        return dp[n - 1];
    }
};

int main() {
    vector<int> arr = {9,2,2,10};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}







//space optimization
// time complexity: O(N) -> where N is the number of elements in the input array
// space complexity: O(1) -> we are using only a constant amount of space to store the maximum sums up to the last two indices, instead of an entire dp array.


class Solution {
public:
    // Function to return maximum sum of non-adjacent elements
    int maxSum(vector<int>& nums) {
        // Handle edge case for empty input
        if (nums.empty()) return 0;

        // Initialize two tracking sums
        int prev2 = 0;
        int prev = nums[0];

        // Traverse through the array
        for (int i = 1; i < nums.size(); i++) {
            // Include current by adding it to two steps back
            int include = nums[i] + prev2;

            // Exclude current by taking previous best
            int exclude = prev;

            // Choose max of include and exclude
            int curr = max(include, exclude);

            // Update tracking variables
            prev2 = prev;
            prev = curr;
        }

        // Final result is stored in prev
        return prev;
    }
};
