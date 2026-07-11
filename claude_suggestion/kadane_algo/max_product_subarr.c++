// https://leetcode.com/problems/maximum-product-subarray/

// brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int product = 1;

            for (int j = i; j < n; j++)
            {
                product *= nums[j];
                ans = max(ans, product);
            }
        }
    }
};


// optimized approach using kadane's algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int mini = nums[0];
        int maxi = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int temp = maxi;
            maxi = max({nums[i],nums[i]*maxi,nums[i]*mini});
            mini = min({nums[i],nums[i]*temp,nums[i]*mini});

            ans = max(maxi,ans);
        }
        return ans;
    }
};