class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int start =0;
       int result = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (nums[mid] == target) {
            result = mid;         
            end = mid - 1;  
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return result;
    }
};