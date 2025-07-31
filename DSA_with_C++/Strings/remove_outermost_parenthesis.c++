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


// time: O(N)
// space: O(1)

/*
check for firstopen parenthesis when it is found make dept++ such that now first element means at dept==1 is
 ignored and now increasing for '(' and now as the ')' will coe will reduce depth to dept-- and if greater than
  zero(means one check if atleast one left for printin after the last is saveed for outermost)
  
  as like dept = 2; ( depth ++1 for the first which have to ignore and then second for the one we have to print)
  depth-- = 1
  it is greater then 0 so one ')'
  then at 0 not greater than 0 so no ')' 
  
  */