class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int last = nums.size()-1;
        int start =0;
        int ans=-1;
        while(start<=last)
        {
            int mid = (start+last)/2;
            if(nums[mid]>x)
            {
                ans=mid;
                last = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};