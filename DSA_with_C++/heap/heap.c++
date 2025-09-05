#include<iostream>
using namespace std;
#include<vector>


class heap
{
    public:
    vector<int> arr;
    heap()
    {
        arr.push_back(-1);
        int size = 0;
    }

   void insert(int val)
{
size+=1;
arr.push_back(val);
int index = size;
while(index>1)
{

int parent = index/2;
if(arr[parent]< arr[index])
{
swap(arr[parent],arr[index]);
index = parent;
}
}
}

int main()
{

}