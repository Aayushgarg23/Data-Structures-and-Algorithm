#include<iostream>
using namespace std;
#include<vector>

void bubbleSort(vector<int>& arr, int n) {
    // Base case
    if (n == 1) return;

    // One pass to move the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call on smaller subarray
    bubbleSort(arr, n - 1);
}

int main()
{
    vector<int> arr = {54,3,86,6,7,15,36,25,49,96,82};
    bubbleSort(arr,arr.size()-1);
    for(int val : arr)
    {
        cout << val << " ";
    }
}