class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.empty()) return "";
        for(int i=0;i<strs[0].size();i++)
        {
            char c = strs[0][i];
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]!=c || i>strs[j].size())
                return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};