#include<iostream>
using namespace std;
int sum(int arr[], int size)
{
if(size==0) return 0;

return arr[0] + sum( arr+1, size-1);

}

int main(){

    int arr[10] = {1,4,5,8,5,85,85,85,858,2};

    cout << sum(arr, 10);
}