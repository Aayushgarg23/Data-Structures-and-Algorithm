//Using the brute force
//time: O(N^2)
//space: O(1)

/*
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == goal) count++;
        }
    }
    return count;
}

*/

//Using the Sliding-Window
//time: O(N)
//space: O(1)

/*

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
    
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0; // if goal-1 < 0, return 0 (no valid subarray)
        
        int l = 0, r = 0;
        int sum = 0, count = 0;
        
        for (r = 0; r < nums.size(); r++) {
            sum += nums[r];
            
            // shrink window if sum > k
            while (sum > k) {
                sum -= nums[l];
                l++;
            }
            
            // all subarrays ending at r and starting from l..r are valid
            count += (r - l + 1);
        }
        return count;
    }
};
*/



//Using the Prefix Sum + HashMap (Optimized Alternative)
//Time: O(n)
//Space: O(n) (map stores prefix sums).
//Use prefix sum + hashmap when elements can be any integers (general case).

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;  
        mp[0] = 1;   // empty prefix has sum 0
        
        int sum = 0, count = 0;
        
        for (int num : nums) {
            sum += num;   // current prefix sum
            
            // check if there's a prefix with (sum - goal)
            if (mp.find(sum - goal) != mp.end()) {
                count += mp[sum - goal];
            }
            
            // store this prefix sum
            mp[sum]++;
        }
        
        return count;
    }
};
