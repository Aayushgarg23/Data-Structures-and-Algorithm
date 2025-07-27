#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> 
int main()
{
    int largest = INT16_MIN;
    int second_largest = INT16_MIN;

    vector<int> arr = {5,5,93,75,41,62,79,25,15,93,56,87,62,06};
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    cout << "Second Largest element is: " << second_largest << endl;
    
}