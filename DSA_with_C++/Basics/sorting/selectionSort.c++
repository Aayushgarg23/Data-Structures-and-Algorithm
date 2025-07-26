#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i =0; i< n-1; i++)
    {
        int min1 = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min1]) min1 = j;
        }
        swap(arr[i],arr[min1]);
    }
    // Write your code here.
}
