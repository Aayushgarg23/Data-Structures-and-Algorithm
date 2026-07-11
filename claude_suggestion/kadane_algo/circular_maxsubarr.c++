


//brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int maxSubarraySumCircular(vector<int>& nums) {

    int n = nums.size();
    int ans = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int len = 0; len < n; len++)
        {
            sum += nums[(i + len) % n];
            ans = max(ans, sum);
        }
    }

    return ans;
}



// optimized approach using kadane's algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax =nums[0];
        int maxi = nums[0];
        int currMin = nums[0];
        int mini =nums[0];
        int total =nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            currMax = max(nums[i], currMax+nums[i]);
            maxi = max(maxi,currMax);
            currMin = min(nums[i],currMin+nums[i]);
            mini = min(mini,currMin);
            total+= nums[i];
        }
        return maxi > 0 ? max(maxi,total-mini) : maxi;
    }
};