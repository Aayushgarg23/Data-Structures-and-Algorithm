#include<iostream>
using namespace std;


int minBitFlip(int n, int x)
{
    int a = n^x; // it will give 1 only on the diff bit so that's why
    int cnt =0;
    while(a!=0)
    {
        cnt++;
        a = a&(a-1);
    }
    return cnt;
}


