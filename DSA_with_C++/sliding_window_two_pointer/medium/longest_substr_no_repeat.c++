#include<bits/stdc++.h>
using namespace std;


// Using the brute force Method 

/*
time: O(N^2)
space: O(N) due to the hashmap 

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}

*/



//Using the sliding window method

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> lastIndex; 
        int l = 0, maxLen = 0;

        for(int r = 0; r < s.length(); r++) {
            if(lastIndex.find(s[r]) != lastIndex.end() && lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1; // shrink window
            }
            lastIndex[s[r]] = r; // update last seen index
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
      }
};
*/

//More optimised way