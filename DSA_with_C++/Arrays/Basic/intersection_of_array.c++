/*
there can be one more way of doing this by making a visit array and then storing n2 index which is visited 
and check if visit[j]==0 and then only insert otherwise if visit[j]==1 then do not insert and break

time: O(n1*n2)
space: O(n2)-> extra use for solving

in that also i can have duplicates allowed 

*/
#include<iostream>
#include<vector>
using namespace std;


vector<int> intersection(vector<int>arr1, vector<int>arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> match;

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] == arr2[j]) {
            if (match.empty() || match.back() != arr1[i])  // avoid duplicates
                match.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
  return match;
}



int main()
{
    vector<int> arr1 = {1,1,2,3,4,6,7,7,8,9};
    vector<int> arr2 = {1,2,2,3,4,6,7,9};

   vector<int>result =  intersection(arr1,arr2);
   for(int val: result)
   {
    cout << val<< " ";
   }
}