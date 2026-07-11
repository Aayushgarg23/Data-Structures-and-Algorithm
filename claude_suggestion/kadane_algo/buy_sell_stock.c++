// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


//optimized approach using kadane's algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= prices[0];
        int profit =0;

        for(int i=0;i<prices.size();i++)
        {
            mini = min(mini,prices[i]);
            int curr = prices[i] - mini;
            profit = max(profit,curr);
        }
        return profit;
    }
};