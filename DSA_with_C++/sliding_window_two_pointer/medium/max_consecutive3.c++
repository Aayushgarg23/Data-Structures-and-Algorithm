/*
Using the brute force method
time : O(N^2)
space : O(1)
/*

int longestOnes(vector<int>& nums, int k) {
    int  n = nums.size();
    int maxLen = 0;
    for(int i=0;i<n;i++)
    {
        int len = 0;
        int zeroes = 0;
        for(int j=i;j<n;j++)
        {
            if(zeroes==k && nums[j]==0)break;
            len++;
            if(nums[j]==0) zeroes++;
            
        }
        maxLen = max(maxLen,len);
    } 
    return maxLen;
    }
*/

