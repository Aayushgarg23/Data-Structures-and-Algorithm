#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void removeDuplicate(vector<int>&arr,int n)
{
    sort(arr.begin(),arr.end());
    int index =0;
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[index])
        {
            arr[index+1] = arr[j];
            index++;
        }
        
    }
    arr.erase(arr.begin()+index+1,arr.end());
}

int main()
{
    vector<int> arr = {1,34,53,1,2,2,2,3,34,4,5,4,6,7,7,9,1};
    removeDuplicate(arr,arr.size());
    for(int val:arr)
    {
        cout << val << " ";
    }
    cout << endl << arr.size();
}




/*

Another method By Using the Unordered Set for More ptimal Solution


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void removeDuplicates(vector<int>& arr) {
    unordered_set<int> seen;
    int insertAt = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[insertAt++] = arr[i]; // write unique element in place
        }
    }

    arr.erase(arr.begin() + insertAt, arr.end()); // remove the rest
}

int main() {
    vector<int> arr = {1, 34, 53, 1, 2, 2, 2, 3, 34, 4, 5, 4, 6, 7, 7, 9, 1};
    removeDuplicates(arr);

    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\nSize: " << arr.size() << endl;
}


*/