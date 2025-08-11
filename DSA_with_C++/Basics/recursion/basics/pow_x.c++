class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00;
       if(n<0)
       {
        for(int i=n;i<0;i++)
        {
            ans = ans* (1/x);
        }
       }
       else { for(int i=0;i<n;i++)
        {
            ans = ans*x;
        }}
    return ans;
    }
};