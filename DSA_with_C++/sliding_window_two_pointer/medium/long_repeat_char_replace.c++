// using the brute force method
// Time Complexity = O(N²)
// Space Complexity = O(1) (only 26 chars stored)

/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;

        // Step 1: try all substrings
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // counts for substring
            for (int j = i; j < n; j++) {
                // Step 2: count current char
                freq[s[j] - 'A']++;

                // Step 3: find max frequency in this substring
                int maxFreq = 0;
                for (int f : freq) {
                    maxFreq = max(maxFreq, f);
                }

                // Step 4: check validity
                int len = j - i + 1;
                int ops = len - maxFreq;
                if (ops <= k) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};
*/

//Using the two pointer sliding window approach
/*
Time Complexity: O(2N) = O(N)
Each l and r move at most n steps.
Frequency updates are O(1).

Space Complexity: O(1) (26 letters).
*/

/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxLen = 0, maxFreq = 0, l=0;

        for(int r=0;r<s.size();r++)
        {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq,freq[s[r]-'A']); // updating at each step to avoid loop

            while((r-l+1)-maxFreq >k)
            {
                freq[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};

*/



//Using the sliding window with more optimal solution
// time: O(N)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxLen = 0, maxFreq = 0, l=0;

        for(int r=0;r<s.size();r++)
        {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq,freq[s[r]-'A']); // updating at each step to avoid loop

            if((r-l+1)-maxFreq >k) // We can use if instead of while as r increasing by 1 not jumping more
            {
                freq[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};