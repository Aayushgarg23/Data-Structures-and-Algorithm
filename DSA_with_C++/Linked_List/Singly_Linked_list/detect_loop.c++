#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
/* Using Brute Force Method
time: O(N*2*Log(N)) two times logN due to the hashmap which will take one logN for insertion and second one for the searching in the list.
space: O(N) for the hashmap

not optimal
*/

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> record;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(record.find(temp)!=record.end()) return true;

            record[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};
*/

/* Using the (slow-fast method) or (floyd-cycle loop detection algorithm) or (the tortoise and hare approach)
time : O(N)
space: O(1)

optimal one
*/
bool hascycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}