#include<iostream>
using namespace std;

void toggleBit(int n, int i)
{
    cout<< ((n ^ (1<<i))) << endl;
}


int main()
{
    toggleBit(13,2);
    
}