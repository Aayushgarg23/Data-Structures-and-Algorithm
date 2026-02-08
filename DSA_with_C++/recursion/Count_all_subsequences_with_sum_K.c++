#include<bits/stdc++.h>
using namespace std;


// this solution is given using the recursion approach to solve the problem in O(2^n) time complexity and O(n) space complexity
// where n is the size of the input array
// we can optimise the above solution using dynamic programming approach to solve the problem in O(n*k) time complexity and O(k) space complexity
class Solution{
    private:
    void solve(vector<int>nums, int k, int &ans, int sum, int idx)
    {
        if(idx==nums.size())
        {
            if(sum==k){
                ans++;
                return;
            }
            return;
        }

        solve(nums, k, ans, sum, idx+1);

        solve(nums,k,ans, sum+ nums[idx],idx+1);

    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        int ans =0;
        int sum =0;
        solve(nums,k,ans,sum,0);
        return ans;
    }
};