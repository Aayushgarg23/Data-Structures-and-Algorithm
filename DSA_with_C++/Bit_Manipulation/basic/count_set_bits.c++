#include<iostream>
using namespace std;

int countSetDigit(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        if(n%2==1)cnt++;
        n/=2;
    }
    return cnt;
}


int main()
{
    cout << countSetDigit(1) << endl;
    cout << countSetDigit(15) << endl;
    cout << countSetDigit(4) << endl;
    cout << countSetDigit(5) << endl;
    cout << countSetDigit(7) << endl;
}