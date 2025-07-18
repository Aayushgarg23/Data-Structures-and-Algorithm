#include<bits/stdc++.h>
using namespace std;

void HCF(int a, int b)

{
    int m = min(a,b);

    for(int i=m;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            cout << i<<endl;
            break;
        }
    }
}


int main()
{
    HCF(4,56);
    HCF(48,238);
    HCF(59,7);
}