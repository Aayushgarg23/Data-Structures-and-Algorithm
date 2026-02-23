#include<bits/stdc++.h>
using namespace std;


int recPar(int n,vector<int>&ulPar)
{
    if(ulPar[n]==n)return n;
    return ulPar[n] = recPar(ulPar[n],ulPar);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3,0));
    for(int i=0;i<m;i++)
    {
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }
    sort(edges.begin(),edges.end());
    vector<int>ulPar(n+1);
    vector<int> size(n+1,1);
    for(int i=1;i<=n;i++)ulPar[i]=i;

    int cnt =0;
    int cost =0;
    for(int i=0;i<m;i++)
    {
        int ulPar1 = recPar(edges[i][1],ulPar);
        int ulPar2 = recPar(edges[i][2],ulPar);

        if(ulPar1==ulPar2)continue;

        if(size[ulPar1]<size[ulPar2])
        {
            ulPar[ulPar1] = ulPar2;
            size[ulPar2]+=size[ulPar1];
        }
        else
        {
            ulPar[ulPar2] = ulPar1;
            size[ulPar1]+=size[ulPar2];
        }
    }
}