// time: O(n)
// space: O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char>s2s,t2s;

        for(int i=0;i<s.length();i++)
        {
            char c1 = s[i]; char c2 =t[i];

            if(s2s.count(c1) && s2s[c1]!=c2 || t2s.count(c2) && t2s[c2]!=c1) return false;

            t2s[c2] = c1;
            s2s[c1] = c2;
        }
return true;
        
    }
};


/*
can use brute force also by using two loops to compare each character like first 
form all then second form all and but time complexity will be O(N^2)
space: O(1);

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                // Check mapping consistency
                if ((s[i] == s[j] && t[i] != t[j]) ||   // case 1
                    (s[i] != s[j] && t[i] == t[j])) {   // case 2
                    return false;
                }
            }
        }

        return true;
    }
};


*/