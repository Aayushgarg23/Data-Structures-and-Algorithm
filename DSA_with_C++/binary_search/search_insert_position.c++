class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int ans=-1;
        int last = nums.size()-1;
        while(start<=last)
        {
            int mid = (start+last)/2;
            if(nums[mid]>=target)
            {
                ans = mid;
                last=mid-1;
            }
            else start = mid+1;
        }
        if(ans==-1) ans = nums.size();
        return ans;
    }
};