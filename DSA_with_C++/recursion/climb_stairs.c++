#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
int countDistinctWays(int nStairs) {
    //  Write your code here.

    if(nStairs < 0) return 0;
    if(nStairs == 0) return 1;

    return countDistinctWays(nStairs-1)+ countDistinctWays(nStairs-2);
     
}

int main()
{
    cout << countDistinctWays(5);
}