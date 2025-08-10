/* using the iterative approach
can be done using the recursive approach as well
.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long reverse=0;
        while(x>0){
        int last = x%10;
        reverse = reverse*10 + last;
        x/=10;
    }
    return reverse==original;
    }
};