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

    void insert(int val) {
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
