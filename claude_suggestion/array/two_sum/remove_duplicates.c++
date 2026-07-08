//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//using the unordered_set to store the unique elements and then copying them back to the original array.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int insertAt = 0;  // pointer for where to place next unique

        for (int i = 0; i < nums.size(); ++i) {
            if (seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
                nums[insertAt++] = nums[i];  // overwrite with unique element
            }
        }

        // Optional: erase the remaining part
        nums.erase(nums.begin() + insertAt, nums.end());

        return insertAt;  // count of unique elements
    }
};





// optimized approach using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int l =1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[l-1])
            {
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};