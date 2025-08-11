#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

//time: log10(N)   dividing by two just like the binary search
//space: log10(N)   
string decimalToString(int n)
{
    string rev = "";
    while(n!=1){
    if(n%2==1) rev+= '1';
    else rev+= '0';
    n = n/2;
}
reverse(rev.begin(),rev.end());
}