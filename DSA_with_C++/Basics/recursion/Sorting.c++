#include<iostream>
using namespace std;

bool issorted(int arr[], int size)
{
    if(size==0 || size==1) return true;

    if(arr[0]> arr[1]) return false;
    bool ans = issorted(arr+1,size-1);

    return ans;

}

int main()

{
    int arr[15] = {1,2,3,4,5,6,7,8,8,12,52};

    if(issorted(arr , 11))
    {
        cout << "Array is sorted";
    }
    else cout<< "Array is not sorted";

}