#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    void solve(string &s, vector<string>& ans, int idx)
    {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        unordered_set<char> used;   // avoid duplicates at this level

        for (int i = idx; i < s.size(); i++) {

            if (used.count(s[i])) continue;  // skip duplicate
            used.insert(s[i]);

            swap(s[idx], s[i]);
            solve(s, ans, idx + 1);
            swap(s[idx], s[i]);   // backtrack
        }
    }

public:
    vector<string> findPermutation(string &s) {

        vector<string> ans;
        solve(s, ans, 0);

        sort(ans.begin(), ans.end());  // GFG requires sorted output
        return ans;
    }
};
