class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int start=0;
        int ans=-1;
        int last = nums.size()-1;
        while(start<=last)
        {
            int mid = (start+last)/2;
            if(nums[mid]==x)
            {
                ans = mid;
                last-=1;
            }
            else if(nums[mid]>x && ans==-1)
            {
                ans = mid;
                last-=1;
            }
            else start = mid+1;
        }
        return ans;
    }
};
/* time: O(logn)
   space: O(1)*/


   /*can done using brute force as well like for loop but that will take time complexity O(N)*/