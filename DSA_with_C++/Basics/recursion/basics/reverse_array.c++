class Solution{
public:
    void reverse(int arr[], int n){
        if(n==0) return ;
        cout<< arr[n-1] << " ";
        reverse(arr,n-1);
    }
};
