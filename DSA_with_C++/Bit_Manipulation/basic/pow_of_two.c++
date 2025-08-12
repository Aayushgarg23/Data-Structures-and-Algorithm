#include<iostream>
using namespace std;



bool powOfTwo(int n)
{
    if(n&(n-1)) return false;
    return true;
}

int main()
{
    cout << powOfTwo(8)<<endl;
    cout << powOfTwo(256)<<endl;
    cout << powOfTwo(19)<<endl;
    cout << powOfTwo(3)<<endl;
}