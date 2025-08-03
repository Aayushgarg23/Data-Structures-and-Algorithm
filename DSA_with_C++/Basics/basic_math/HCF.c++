#include<bits/stdc++.h>
using namespace std;



/*optimal: 
Euclediean method
if i use the same method using the recurion the time will be same but due to repetitive recursive call stack memory will be high O(logn)
time O(logmax(n1,n2))   space:O(1)
*/

void HCF(int a, int b)
{
    while(a>0 && b>0)
    {
        if(a>b) a%=b;
        else b%= a;    
    }
    if(b==0) cout<< a;
    else cout<< b;
    cout<<endl;
}


/*
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
*/

int main()
{
    HCF(4,56);
    HCF(48,238);
    HCF(59,7);
    HCF(5,5);
}