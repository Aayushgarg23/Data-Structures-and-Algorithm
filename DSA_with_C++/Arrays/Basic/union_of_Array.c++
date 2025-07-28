/*
we can use set not unordered set ( will take elemtn without order ) but not using set bcz
 then the time and space complexity will be high as set will take 
 (logn) for insert fucntion and for performing n times for iteration it will take 

 time : O(n1logn + n2logn) + O(n1+n2)
space : O(n1+n2) + O(n1+n2) where seconnd O(n1+n2) is to return the ans not solving
*/


/* current 
time complexity : o(n1+n2)
space complexity : o(n1+n2)

*/
#include<bits/stdc++.h>
using namespace std;

vector <int> sortedArray(vector<int>& arr1, vector<int>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionArr ;
    int i=0;
    int j=0;
    while (i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(unionArr.size()==0 || unionArr.back()!= arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
        else if(arr2[j]<=arr1[i])
        {
              if(unionArr.size()==0 || unionArr.back()!= arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
        }
    }
    
    while(i<n1)
    {
            if(unionArr.size()==0 || unionArr.back()!= arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j<n2)
    {
        if(unionArr.size()==0 || unionArr.back()!= arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
    }

    

    


int main()
{
    vector<int>arr1 = {1,2,3,3,3,3,4,5,6,6,7,8};
    vector<int>arr2 = {1,1,2,3,4,56,87,98,99,876,65776};
    vector <int> result =sortedArray(arr1,arr2);
    for(int val : result)
    {
        cout << val <<" ";
    }
}
