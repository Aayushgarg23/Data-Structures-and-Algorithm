#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        map<int,int>hash;

        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        for(auto a: hash)
        {
            if(a.second >m)
            return a.first;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int>nums = {2,2,1,1,1,2,2};
    cout<<obj.majorityElement(nums);
    return 0;
}