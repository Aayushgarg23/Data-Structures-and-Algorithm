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

        // exclude i.e we will not include the element in the output and then move to the next index
        solve(arr, output, ans, idx + 1);
       
        // include i.e we will include the element in the output and then move to the next index
        output.push_back(arr[idx]);
        solve(arr, output, ans, idx + 1);
        output.pop_back(); // backtracking step to remove the last element added to the output vector and explore other possibilities
    // if use output not as reference then we don't need to pop_back() as we will be creating a new copy of the output vector in each recursive call and we won't be modifying the same output vector in different recursive calls. But using reference is more efficient as it avoids unnecessary copying of the output vector in each recursive call, which can save both time and memory, especially when the output vector is large.
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(arr, output, ans, 0);
        return ans;
    }
};
