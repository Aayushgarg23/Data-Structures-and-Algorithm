class Solution {
public:
    bool isArmstrong(int n) {
        int original =n;
        int size = log10(n)+1;
        int sum=0;
        while(n>0)
            {
              int last = n%10;
              sum+= pow(last,size);
              n/=10;
            
            }
return original==sum;
    }
};