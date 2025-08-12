#include<iostream>
using namespace std;

/* my task it to set the ith bit to the 1 so i can do it in both way by converting to binary and then use brute force and make ith bit
one and then convert to the decimal but it's a log process with more complexity


Second and optimal method to do so it to use the bit operator */


void setBit(int n, int i)
{
    cout<< ((n | (1<<i))) << endl;
}


int main()
{
    setBit(9,2);
}