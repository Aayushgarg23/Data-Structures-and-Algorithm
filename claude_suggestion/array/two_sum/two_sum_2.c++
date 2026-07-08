//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/2059993501/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        int sum =0;
        vector<int>ans;

        while(l!=r)
        {
            if(numbers[l]+numbers[r]==target)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(numbers[l]+numbers[r]<target)l++;
            else r--;
        }
        return ans;
    }
};