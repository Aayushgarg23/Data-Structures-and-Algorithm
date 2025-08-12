#include<iostream>
using namespace std;

/* my task it to set the ith bit to the 0 so i can do it in both way by converting to binary and then use brute force and make ith bit
zero and then convert to the decimal but it's a log process with more complexity


Second and optimal method to do so it to use the bit operator */

/*using the XOR method:
in this method there is a problem that when the bit will be already zero
it will make that one which is not efficient */

/*void clearBit(int n, int i)
{
    cout<< ((n ^ (1<<i))) << endl;
}
*/


// Most optimal way is to do by using the And + NOT operator

void clearBit(int n, int i)
{
    cout << (n & (~(1<<i))) << endl; // it will first become ....0010... and after not ..11011.. and zero and will make for sure zero and rest acc
    // to respective zero or one
}

int main()
{
    clearBit(13,2);
}