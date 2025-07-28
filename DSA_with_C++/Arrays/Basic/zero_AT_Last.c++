class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =-1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                j=i;
                break;
            }
        }
        if(j!=-1){  // necessary to check if there are no zeroes because otherwise there will come error in swap(arr[i],arr[j=-1])
        for(int i=j+1;i<n;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }}
        }
    }
};