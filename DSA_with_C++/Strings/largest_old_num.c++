#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        if(num.length()>0){
            cout << "Input: " << num << ", length: " << num.length() << endl;

        for(int i=num.length()-1;i>=0;i++)
        {
            int digit = num[i] ;
            if(digit%2 !=0)
            {
                return num.substr(0,i+1);
            }
        }}
        return "";
    }
};
int main() {
    Solution sol;  // create object of Solution
    string result = sol.largestOddNumber("12546217");  // call method using object
    cout << "Largest odd number: " << result << endl;
    return 0;
}
