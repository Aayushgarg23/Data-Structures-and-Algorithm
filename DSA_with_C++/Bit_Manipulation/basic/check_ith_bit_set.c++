#include<iostream>
using namespace std;

bool bitSet(int n, int bit) // using the right shift operator
{
    if(((n>>bit) & 1) ==0) return false;
    return true;
}


bool bitSetLeft(int n, int bit)   // using the left shift operator
{
    if((n & (1<<bit)) ==0) return false;
    return true;
}

int main()
{
    cout << bitSet(1,0) << endl;
    cout << bitSetLeft(10,2);
}