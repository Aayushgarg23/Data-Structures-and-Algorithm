#include<bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1744

int minMoves(int a, int b)
{
    if(a==b)return 0;
    
    int ans = 1e9;
    //dp

    for(int i=1; i<a;i++)
    {
        int tempAns = 1+minMoves(i,b) + minMoves(a-i,b);
        ans = min(ans, tempAns);
    }
    
    for(int i=1;i<b;i++)
    {
        int tempAns = 1+minMoves(a,i) + minMoves(a,b-i);
        ans = min(ans, tempAns);
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<minMoves(a,b)<<endl;

    
}

// optimal solution

