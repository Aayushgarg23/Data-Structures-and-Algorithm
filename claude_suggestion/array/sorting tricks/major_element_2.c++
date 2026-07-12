// https://leetcode.com/problems/majority-element-ii/description/


// there are multiple methods like :
// 1. brute force approach by using two loops and counting the frequency of each element and checking if it is greater than n/3 or not.
// 2. sorting approach by sorting the array and checking the middle element.
// 3. hash map approach by storing the frequency of each element in a hash map and checking if it is greater than n/3 or not.

//brute force approach
vector<int> ans;

for(int i=0;i<n;i++)
{
    int cnt=0;

    for(int j=0;j<n;j++)
    {
        if(nums[i]==nums[j])
            cnt++;
    }

    if(cnt>n/3 &&
       find(ans.begin(),ans.end(),nums[i])==ans.end())
    {
        ans.push_back(nums[i]);
    }
}


// optimized approach using Moore's Voting Algorithm
// we can have at most 2 majority elements in the array
// so we can maintain two candidates and their counts and then check if they are greater than n/3 or not.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int candidate1 = 0;
        int candidate2 = 1;

        int count1 = 0;
        int count2 = 0;

        for(int num : nums)
        {
            if(num == candidate1)
                count1++;

            else if(num == candidate2)
                count2++;

            else if(count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }

            else if(count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }

            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int num : nums)
        {
            if(num == candidate1)
                count1++;
            else if(num == candidate2)
                count2++;
        }

        vector<int> ans;

        if(count1 > nums.size()/3)
            ans.push_back(candidate1);

        if(count2 > nums.size()/3)
            ans.push_back(candidate2);

        return ans;
    }
};