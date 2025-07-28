class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
         k = k% n;
    vector<int> temp;
    for(int i=n-k;i<n;i++)
    {
        temp[i-(n-k)] = nums[i];
    }

    for(int i =n-1; i>=k;i--)
    {
        nums[i] = nums[i-k];
    }
    for(int i =0; i<k;i++)
    {
        nums[i] = temp[i];
    }

    }
};

/*
for more optimisation and save the o(n) extra space from the space comlexity we can use the reverse function as well
reverse the elements form 
1234567 -> 5671234
reverse this part 567
reverse 1234
then reverse whole array
the time complexity will remain same but space will be optismised
*/