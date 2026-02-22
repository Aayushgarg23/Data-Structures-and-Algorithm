#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/house-robber-ii/description/


class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)return 0;
        else if(n==1)return nums[0];
        else if(n==2)return max(nums[0],nums[1]);

        int prev2 =0;
        int prev = nums[0];

        for(int i=1;i<n-1;i++)
        {

            int include = nums[i] + prev2;
            
            int exclude = prev;

            int curr = max(include,exclude);

            prev2 = prev;
            prev = curr;
        }
        
        prev2 =0;
        int temp = nums[1];

        for(int i=2;i<n;i++)
        {

            int include = nums[i] + prev2;
            
            int exclude = temp;

            int curr = max(include,exclude);

            
            prev2 = temp;
            temp = curr;
        }
return max(prev,temp);
    }
};