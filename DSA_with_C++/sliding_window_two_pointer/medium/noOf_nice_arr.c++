// similar to the binary subarray count just consider even as 0 and odd as 1

class Solution {
    private:
     int atmost(vector<int>& nums, int k){
         if (k < 0) return 0; // if goal-1 < 0, return 0 (no valid subarray)
        
        int l = 0, r = 0;
        int sum = 0, count = 0;
        
        for (r = 0; r < nums.size(); r++) {
            sum += nums[r]%2;
            
            // shrink window if sum > k
            while (sum > k) {
                sum -= nums[l]%2;
                l++;
            }
            
            // all subarrays ending at r and starting from l..r are valid
            count += (r - l + 1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);}};
       
