#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> 
int main()
{
     int largest = INT_MIN;
    int second_largest = INT_MIN;


    vector<int> arr = {5,5,93,75,41,62,79,25,15,93,56,87,62,06};
    
      for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>largest)
        {
            second_largest = largest;
            largest = nums[i];
        }
        else if(nums[i] < largest && nums[i] > second_largest)
        {
            second_largest = nums[i];
        }
    }
    if (second_largest == INT_MIN)
            return -1;
    cout << "Second Largest element is: " << second_largest << endl;

    return 0;
    
}