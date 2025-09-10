#include<iostream>
using namespace std;


void minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    int res = 0;

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res += first + second;
        pq.push(first + second);
    }

    cout << res << endl;
    
}

int main()
{
    return 0;
}