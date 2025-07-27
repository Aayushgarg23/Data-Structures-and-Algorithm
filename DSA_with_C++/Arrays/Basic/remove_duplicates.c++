#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void removeDuplicate(vector<int>&arr,int n)
{
    sort(arr.begin(),arr.end());
    int index =0;
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[index])
        {
            arr[index+1] = arr[j];
            index++;
        }
        
    }
    arr.erase(arr.begin()+index+1,arr.end());
}

int main()
{
    vector<int> arr = {1,34,53,1,2,2,2,3,34,4,5,4,6,7,7,9,1};
    removeDuplicate(arr,arr.size());
    for(int val:arr)
    {
        cout << val << " ";
    }
    cout << endl << arr.size();
}