#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;        // Base case
    int ans= n * factorial(n - 1); 
    return ans;
}

int main()
{
    cout <<factorial(4);
}
