/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]==nums[i])
                {
                    cnt++;
                }
            }
            if(cnt==1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

brute force
time: O(n^2)
space: O(N)
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
