#include <iostream>
using namespace std;

int binarysearch(int arr[], int start, int end, int key)
{
    if (start > end) return -1; // base case: not found

    int mid = (start + end) / 2;

    if (arr[mid] == key) return mid;

    if (arr[mid] < key)
        return binarysearch(arr, mid + 1, end, key);
    else
        return binarysearch(arr, start, mid - 1, key);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 753}; // ✅ Sorted array required
    int key = 5;

    int result = binarysearch(arr, 0, 4, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
