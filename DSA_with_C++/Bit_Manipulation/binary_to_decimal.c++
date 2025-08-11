#include<iostream>
using namespace std;


int binaryToDecimal(string s)
{
    int len = s.length();
    int num = 0; int pow2 = 1; // 2^0 = 1
    for(int i= len-1;i>=0;i--)
    {
        if(s[i]=='1') {
            num+= pow2;
        }
        pow2 *= 2;
    }
    return num;
}

int main() {
    string bin = "101"; // should be 5
    cout << binaryToDecimal(bin) << endl;
    return 0;
}