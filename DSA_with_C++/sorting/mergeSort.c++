#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e-s)/2;
    int l1 = mid - s + 1;
    int l2 = e-mid;

    int *first = new int[l1];
    int *second = new int[l2];

    int mainIndex = s;

    for(int i=0;i<l1;i++)
    {
        first[i] = arr[mainIndex++];
    }
    
    for(int i=0;i<l2;i++)
    {
        second[i] = arr[mainIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while(index1<l1 && index2<l2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainIndex++] = first[index1++]; 
        }
        else
        {
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1<l1)
    {
        arr[mainIndex++] = first[index1++]; 
    }
    while(index2<l2)
    {
        arr[mainIndex++] = second[index2++]; 
    }
    delete []first;
    delete []second;
}

void mergesort(vector<int>& arr, int s, int e)
{

    if(s>=e) return;
    int mid = s + (e-s)/2; // In this way to avoid overflow due to s+ e if both are int max
//left part sorting
    mergesort(arr, s,  mid);
// Right part sorting
    mergesort(arr, mid+1, e);
// Merge both parts
    merge(arr,s,e);
}

int main()

{
    vector<int> arr = {1,2,3,23,64,5,253,756,32,24};

    mergesort(arr, 0, arr.size()-1);
    for (int val : arr) {
    cout << val << " ";
}

}