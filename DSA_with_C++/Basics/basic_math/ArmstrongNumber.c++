class Solution {
public:
    bool isArmstrong(int n) {
        int original =n;
        // Can be done by two methods one by using the two loops and count the number of the digit is zero
        int size = log10(n)+1;  // log10(N) give number of digit -1 approx so add one to it
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