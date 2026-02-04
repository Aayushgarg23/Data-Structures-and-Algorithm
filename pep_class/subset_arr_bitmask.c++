#include<bits/stdc++.h>
using namespace std;

int mian()
{
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    for(int mask=0;mask<(1<<n);mask++)
    {
        vector<int> subset;
        for(int i=0;i<n;i++)
        {
            if(mask & (1<< i)) subset.push_back(nums[i]);
        }
for(auto it: subset) cout<<it<<" ";
        cout<<endl;
    }
}