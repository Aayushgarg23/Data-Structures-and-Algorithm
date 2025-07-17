#include<iostream>
using namespace std;


int searchIndex(int arr[], int size, int k, int index = 0) {
    if (size == 0) return -1;  // base case: not found

    if (arr[0] == k) return index;  // found at current index

    // recursive call on rest of the array
    return searchIndex(arr + 1, size - 1, k, index + 1);
}

int main()
{
int arr[50] = {1,5,6546,4,4,8,48,1,4,6,94,6};
int k = 48;
cout << searchIndex(arr, 50, k,0);
return 0;
}