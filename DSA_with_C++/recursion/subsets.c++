#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<int>& arr,
               vector<int>& output,
               vector<vector<int>>& ans,
               int idx)
    {
        if (idx == arr.size()) {
            ans.push_back(output);
            return;
        }

        
        solve(arr, output, ans, idx + 1);
       
        output.push_back(arr[idx]);
        solve(arr, output, ans, idx + 1);
        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(arr, output, ans, 0);
        return ans;
    }
};
