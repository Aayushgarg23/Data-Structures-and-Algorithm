#include<iostream>
using namespace std;


/*  Using the brute force without chnaging to the binary number
Time Complexity: O(log n)
In worst case, we will check all bits until we find the first set one.
For a 32-bit int, this is O(32) → O(1) in practice, but theoretically O(log n) for arbitrary integers.

Space Complexity: O(1)

void removeLastSetBitBrute(int n) {
    // Find index of rightmost set bit
    int pos = -1;
    for (int i = 0; i < 32; i++) {  // assuming 32-bit int
        if ((n >> i) & 1) { // check if bit at position i is set
            pos = i;
            break; // found the rightmost 1
        }
    }
    
    if (pos != -1) {
        n = n - (1 << pos); // remove that set bit
    }
    cout << n << endl;
}

int main() {
    removeLastSetBitBrute(8);   // 0
    removeLastSetBitBrute(13);  // 12
    removeLastSetBitBrute(45);  // 44
}

*/


/* optimal way for doing it

Time Complexity: O(1)
Space Complexity: O(1)*/
void removeLastSetBit(int n)
{
    cout << (n & (n-1))<< endl;
}


int main()
{
    removeLastSetBit(8);
    removeLastSetBit(13);
    removeLastSetBit(45);
}