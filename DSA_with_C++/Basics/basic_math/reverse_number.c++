#include<bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    while(n>0)
    {
        int last = n%10;
        n/=10;
        if(last!=0) cout << last;
    }
}

int main()
{
    int n;
    cin >> n;
    reverse(n);
}