/*

Better Approach(using Hashing): 
Space Complexity: O(N) as we use the map data structure.
Time Complexity: O(N), where N = size of the array.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>sum;

        for(int i =0;i<n;i++)
        {
            int num = nums[i];
            int require = target-num;
            if(sum.find(require)!= sum.end()) return {sum[require],i};
            sum[num] = i;
        }
        return {-1,-1};
    }
};



/*

Optimized Approach(using two-pointer): 
Space Complexity: O(1) as we are not using any extra space.
Time Complexity: O(N) + O(N*logN), where N = size of the array.

we need to sort in this approch so taking N*log(N) but if it is already sorted then we can definitly use this method
*/

/*
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
*/