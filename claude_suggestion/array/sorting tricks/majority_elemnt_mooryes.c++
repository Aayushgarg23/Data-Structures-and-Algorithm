// https://leetcode.com/problems/majority-element/description/


// there are multiple methods like :

// 1. brute force approach by using two loops and counting the frequency of each element and checking if it is greater than n/2 or not.
// 2. sorting approach by sorting the array and checking the middle element.
// 3. hash map approach by storing the frequency of each element in a hash map and checking if it is greater than n/2 or not.
// 4. Moore's Voting Algorithm approach by maintaining a candidate and a count, and updating them based on the current element.

// optimized approach using Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate =0;
        int cnt =0;

        for(int num:nums)
        {
            if(cnt==0)candidate = num;
            else if(cnt==candidate)cnt++;
            else cnt--;
        }
        return candidate;
    }
};