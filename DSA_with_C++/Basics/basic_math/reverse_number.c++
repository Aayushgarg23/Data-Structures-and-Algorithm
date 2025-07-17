#include<bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int rev=0;
    while(n>0)
    {
        int last = n%10;
        n/=10;
        rev = (rev*10)+last;
    }
    cout << rev;
}

int main()
{
    int n;
    cin >> n;
    reverse(n);
}