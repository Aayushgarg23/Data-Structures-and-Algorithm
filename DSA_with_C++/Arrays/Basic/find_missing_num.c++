//Method 1st

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();

        for(int i=0;i<=n;i++)
        {
            int flag = 0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]==i)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                return i;
            }
        }
      return -1; }
 
};

time: O(N^2)
space: O(1)

*/

// Method two

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        vector<int> hash(n+1);
        for(int i=0;i<n;i++)
        {
            hash[nums[i]] = 1;
        } 
        for(int j =0; j<hash.size();j++)
        {
            if(hash[j]==0)
            {
                return j;
            }
        }
        return -1;
    }
};


time: O(N) + O(N)
space: O(N)
*/


// most optimised way
/*
use sum such that sum of first natural number and then subtract 
the digit missing will come wheter it's zero or non-zero

time: O(N);
space: O(1);
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int actual = n*(n+1)/2;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
        }
        int result =actual- sum ;
        return result;
    }
};