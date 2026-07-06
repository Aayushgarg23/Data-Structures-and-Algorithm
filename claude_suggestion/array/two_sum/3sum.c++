//https://leetcode.com/problems/3sum/submissions/2058185908/


#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time Complexity: O(n^3)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>>st;
     int n = nums.size();
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {{
            for(int k=j+1;k<n;k++)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }}
     }   
     
     vector<vector<int>>ans(st.begin(),st.end());
     return ans;
    }
};


// Optimized Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

vector<vector<int>> ans;
set<vector<int>> st;

for(int i=0;i<n;i++)
{
    unordered_set<int> hash;

    for(int j=i+1;j<n;j++)
    {
        int third = -(nums[i]+nums[j]);

        if(hash.find(third)!=hash.end())
        {
            vector<int> temp={nums[i],nums[j],third};

            sort(temp.begin(),temp.end());

            st.insert(temp);
        }

        hash.insert(nums[j]);
    }
}

return vector<vector<int>>(st.begin(),st.end());