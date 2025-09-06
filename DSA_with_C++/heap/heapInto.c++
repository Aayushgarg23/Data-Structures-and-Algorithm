#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> arr;
    int size; // <-- make size a member variable

    MaxHeap() {
        arr.push_back(-1); // index 0 is dummy
        size = 0;
    }

    void insert(int val) {   // O(log n) time complexity to insert an element in heap 
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

    void deleteFromHeap() { // always deleting root node which is the max element in max heap 
        // O(log n) time complexity to delete an element from heap
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        arr.pop_back();
        size--;

        int index = 1;
        while (index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void heapify(int index) { // in heapify also we are taking node to corect position like delete but not deleting anythingso no need to decrease size
        // O(log n) time complexity to heapify an element
        int left = 2 * index;
        int right = 2 * index + 1;
        int largest = index;

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void buildHeap() {
    for(int i = size / 2; i > 0; i--) { // building heap from an array in O(n) time. We start from size/2 because all nodes after that are leaf nodes and already satisfy heap property
        heapify(i);
    }
    }

    void heapSort() { // O(n log n) time complexity to sort an array using heap sort
        //it is in place sorting algorithm but not stable
        // heap sort is just a method to sort an array using heap data structure
        int originalSize = size; // Store the original size of the heap
        for (int i = 0; i < originalSize; i++) {
            // just printing and deleting the root element one by one not other thing bcz after deleting root element heapify will take care of re-heapifying the heap
            cout << arr[1] << " "; // The root element is the largest
            deleteFromHeap(); // Remove the root element and re-heapify
        }
        cout << endl;
    }
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    return 0;
}
