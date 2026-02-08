#include<bits/stdc++.h>
using namespace std;

// using the recursion to generate all the binary string of length n same as the power set of a string of length n
// power set is the set of all the subsets of a string including the empty set and the string itself
// for example the power set of "abc" is {"", "a", "b", "c", "ab", "ac", "bc", "abc"}
// power set of a string of length n has 2^n subsets including the empty set and the string itself

// User function template for C++
class Solution {
    private:
    void solve(int n, int &ans, string &output, int idx)
    {
        if(idx==n)
        {
            ans++;
            return;
        }
        
        // check for the all zeros (try placing the zero only)

        output.push_back('0');
        solve(n, ans, output, idx+1);
        output.pop_back();

        // check if possible to place the one now

        if(output.empty() || output.back()!='1')
        {
            output.push_back('1');
            solve(n, ans, output, idx+1);
            output.pop_back();
        }
        
    }
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        int ans=0;
        string output = "";
        solve(n, ans, output, 0);
        return ans;
    }
};


int main()
{
    int n = 3;
    Solution ob;
    cout << ob.countStrings(n) << endl; // Output: 5
    return 0;
}



// this is the optimized version of the above code using dynamic programming approach to
// solve the problem in O(n) time complexity and O(1) space complexity

// The idea is to use the Fibonacci sequence to count the number of binary strings of length n without consecutive 1s.
// the idea is based on the visuaization of the pattern in raw form and then add in dp form to optimize the code and avoid the recursion and the exponential time complexity of the above code
class CountBinaryStrings {
   
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        if (n == 1) return 2;
        if (n == 2) return 3;

        long long prev2 = 2;  // dp[1]
        long long prev1 = 3;  // dp[2]
        long long curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};