/* using the brute force method*/

class Solution {
public:
   /* int singleNumber(vector<int>& nums) {
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
*/

/*optimal using the bits*/

int singleNumber(vector<int>& nums) {
         int ans = 0;  
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }