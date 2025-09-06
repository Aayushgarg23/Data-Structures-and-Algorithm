#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int kthsmallest(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1]; // kth smallest element is at index k-1 after sorting
    // Time Complexity: O(n log n) due to sorting
    // Space Complexity: O(1) if sorting in place, otherwise O(n)
}

int kthSmallestUsingMaxHeap(vector<int> &arr, int k) {
    priority_queue<int> maxHeap; // max heap to store the k smallest elements

    for (int i = 0; i < arr.size(); i++) {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k) {
            maxHeap.pop(); // remove the largest element among the k+1 elements
        }
    }

    return maxHeap.top(); // the root of the max heap is the kth smallest element

    // Time Complexity: O(n log k) where n is the number of elements in the array
    // Space Complexity: O(k) for storing k elements in the heap
}

int kthsmallestUsingMinHeap(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to store all elements

    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
    }

    // remove the smallest element k-1 times
    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }

    return minHeap.top(); // the root of the min heap is the kth smallest element
    // Time Complexity: O(n + k log n) where n is the number of elements in the array
    // Space Complexity: O(n) for storing all elements in the heap
}
// out of these three methods using max heap is the most optimal one

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "The " << k << "th smallest element is: " << kthSmallest(arr, k) << endl;
    return 0;
}