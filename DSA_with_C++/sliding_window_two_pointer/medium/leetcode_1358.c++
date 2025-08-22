/*
Using the brute force method
time: O(N^2)
space = O(3)~O(1)
*/

/*
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            int hash[3] {0};
            
            for(int j=i;j<s.size();j++)
            {
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3)
                {
                    cnt++;
// we can use this as well for optimisation instead of cnt++ as no need to check further after a string found 
                    // cnt+= s.size()-j; break;
                }
            }
        }
        return cnt;
    }
};
*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int last[3] = {-1, -1, -1}; // last seen index of 'a', 'b', 'c'
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            last[s[i]-'a'] = i;  // update last seen position
            
            // Only valid when all 3 chars are seen at least once
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                // Minimum index among last[0], last[1], last[2]
                int minIndex = min({last[0], last[1], last[2]});
                
                // All substrings ending at i and starting before/equal to minIndex are valid
                cnt += minIndex + 1;
            }
        }
        
        return cnt;
    }
};

