#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
void solve(vector<int> candidates, int target, vector<vector<int>> &ans, int idx, vector<int> output)
    {
        if(target==0) {
        ans.push_back(output);
        return;
        }
        if(idx == candidates.size() || target <0)
        {
                return;
        }
        
        output.push_back(candidates[idx]);
        solve(candidates, target-candidates[idx], ans, idx, output);
        output.pop_back();

        solve(candidates, target, ans, idx+1, output);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates, target, ans, 0, output);
        return ans;
    }
};