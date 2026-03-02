#include<bits/stdc++.h>
using namespace std;



// Brute Force Solution
// Time Complexity: O(2^(2n) * n) - There are 2^(2n) possible combinations of parentheses, and checking if each combination is valid takes O(n) time.
// Space Complexity: O(n) - The maximum depth of the recursion is n, which occurs when we have n open parentheses followed by n close parentheses.
class Solution {
    private:

    void valid(string s)
    {
        int balance=0;

        for(auto c:s)
        {
            if(c=='(')balance++;
            else balance--;
            if(balance<0)return false;
        }
return balance==0;
    }
    void generate(string curr,int n,vector<string>&res)
    {
        if(curr.length()==2*n)
        {
            if(valid(curr))res.push_back(curr);
        }

        generate(curr+'(',n,res);
        generate(curr+')',n,res);
    }
    public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;

        generate("",n,res);

        return res;
    }
    }



// Optimized Solution
// Time Complexity: O(4^n / sqrt(n)) - This is the number of valid combinations of parentheses, which is given by the nth Catalan number.
// Space Complexity: O(n) - The maximum depth of the recursion is n, which occurs
// when we have n open parentheses followed by n close parentheses.
class Solution {
public:

void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) backtrack(curr + '(', open + 1, close, n, res);
    if (close < open) backtrack(curr + ')', open, close + 1, n, res);
}

    vector<string> generateParenthesis(int n) {
        vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
    }
};