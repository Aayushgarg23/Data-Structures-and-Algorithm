#include<iostream>
using namespace std;
#include<string>


/* brute force */
bool bruterotated(string s, string goal)
{
    if(s==goal) return true;
    if(s.length()!=goal) return false;
    
    for(int i=0;i<s.length;i++)
    {
        string rotated = s.substr(i) + s.substr(0,i);
        if(rotated==goal) return true;
    }
    return false;

}


/*another way (optimised one)*/

// time : O(N)
// space : O(N)


bool  find(string s, string goal)
{
    if(s==goal) return true;
    if(s.length()!=goal.length()) return false;
    string double_str = s+s;
    int index = double_str.find(goal);
    if(index<s.length()) return true;
    return false;

}