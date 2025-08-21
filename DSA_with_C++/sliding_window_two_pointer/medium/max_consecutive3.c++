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


// Using the Two Pointers and the Sliding window approach
// time: O(N)+O(N) = O(2N)
// space: O(1)

/*
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int  n = nums.size();
    int maxLen = 0; int l=0; int r=0;
    int zeroes =0;
    while(r<n)
    {
        if(nums[r]==0)zeroes++;
        if(zeroes>k)
        {
            while(zeroes>k)
            {
                if(nums[l]==0) zeroes--;
                l++;
            }
        }
        r++;  // if I will use this line after the maxLen updation line then i will have to use the r-l+1
        maxLen = max(maxLen,r-l);

    }
return maxLen;
    }
};
*/



// Using the Same sliding window and two pointers but in more efficient way
// time : O(N)
// space: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int  n = nums.size();
    int maxLen = 0; int l=0; int r=0;
    int zeroes =0;
    while(r<n)
    {
        if(nums[r]==0)zeroes++;
        if(zeroes>k)
        {
           
                if(nums[l]==0) zeroes--;
                l++;
        }
        r++;
        if(zeroes<=k)maxLen = max(maxLen,r-l);

    }
return maxLen;
    }
};