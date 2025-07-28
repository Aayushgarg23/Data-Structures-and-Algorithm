/*there is one more approach other than we use such that we will make a temp array and will store non zero in that
 and then cop to originia one starting and then make furhter form temp size to zero*/

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