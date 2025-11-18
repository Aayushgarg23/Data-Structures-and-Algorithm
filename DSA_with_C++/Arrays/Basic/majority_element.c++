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
/*
Time Complexity: O(N*logN) + O(N), where N = size of the given array.

Reason: We are using a map data structure. Insertion in the map takes logN time. 
And we are doing it for N elements. So, it results in the first term O(N*logN). 
The second O(N) is for checking which element occurs more than floor(N/2) times.
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case,
it will be O(N2).

space Complexity: O(N), where N = size of the given array.
*/

// optimal approach (Boyer-Moore Voting Algorithm)


