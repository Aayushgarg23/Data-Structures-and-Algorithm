class Solution {
public:
    string removeOuterParentheses(string s) {
         int dept = 0;
         string res = "";
         for(char c: s)
         {
            if(c=='(')
            {dept++;
                if(dept>1)
                {
                    res+=c;
                    
                }
            }
            else
            { dept--;
            if(dept>0)
            res+= c;
         }
           }
           return res;  }
};