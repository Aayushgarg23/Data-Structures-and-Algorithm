#include<bits/stdc++.h>
using namespace std;

void prime(int n)
{
    int cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cnt++;
            if(n/i!=i) cnt++;
        }
    }
    if(cnt ==2 ) cout << "Prime number" << endl;
    else cout<< "Not a Prime NUmber" << endl;
}

int main()
{
    prime(2);
    prime(5);
    prime(24);
    return 0;
}