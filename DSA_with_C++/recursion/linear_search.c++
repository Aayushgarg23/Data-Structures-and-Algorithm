#include<iostream>
using namespace std;


bool search(int arr[], int size, int k)
{
    if(size==0)
    {
        return false;
    }
    if(arr[0]==k)
    {
        return true;
    }
    else{
        return search(arr+1, size-1, k);
    }
}
int main()
{
int arr[50] = {1,5,6546,4,4,8,48,1,4,6,94,6};
int k = 484;
cout << search(arr, 50, k);
}