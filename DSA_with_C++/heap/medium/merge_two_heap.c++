#include<iostream>
#include<vector>
using namespace std;


void insert(int val, int &size, vector<int> &arr) {   // O(log n) time complexity to insert an element in heap 
        size += 1;
        arr.push_back(val);
        int index = size;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

void mergeHeapsByInsertion(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
    {
        int size = 0;
    for(int i=0; i<arr1.size(); i++)
        insert(arr1[i], size, merged);
    for(int i=0; i<arr2.size(); i++)
        insert(arr2[i], size, merged);
    
    for(int i=1; i<=size; i++)
        cout<<merged[i]<<" ";

// Time Complexity: O((m+n) log(m+n)) where m and n are the sizes of the two heaps and m is the size of the smaller heap 
// Space Complexity: O(1) if we don't consider the output array, otherwise O(m+n) for the output array

// Auxiliary Space: O(1)
}

void mergeHeapByBuildHeap(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
    for(int i=0; i<arr1.size(); i++)
        merged.push_back(arr1[i]);
    for(int i=0; i<arr2.size(); i++)
        merged.push_back(arr2[i]);
    
    int size = merged.size()-1; // since we have a dummy element at index 0

    for(int i=size/2; i>=1; i--) // O(n) time complexity to build a heap
    {
        int index = i;
        while (index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && merged[left] > merged[largest]) {
                largest = left;
            }
            if (right <= size && merged[right] > merged[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(merged[index], merged[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    for(int i=1; i<=size; i++)
        cout<<merged[i]<<" ";

    // Time Complexity: O(m+n) where m and n are the sizes of the two heaps
    // Space Complexity: O(1) if we don't consider the output array, otherwise O(m+n) for the output array
}
int main()
{
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};
    vector<int> merged = {-1}; // dummy element at index 0
    
    return 0;
}

