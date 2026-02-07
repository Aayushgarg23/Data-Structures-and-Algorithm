#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digits, string output, vector<string>& ans, string map[], int idx)
    {
        if(idx==digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[idx] - '0';

        string val = map[number];

        for(int i=0;i<val.length();i++)
        {
            output.push_back(val[i]);
            solve(digits,output,ans,map,idx+1);
            output.pop_back();            
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string output ="";
        vector<string>ans;

        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits,output, ans, map, 0);
        return ans;
    }
};